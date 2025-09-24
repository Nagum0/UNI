#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <time.h>
#include <mqueue.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>

int patience = 0;

void szemafor_muvelet(int semid, int op){
    struct sembuf muvelet;
    
    muvelet.sem_num = 0;
    muvelet.sem_op  = op; // op=1 up, op=-1 down 
    muvelet.sem_flg = 0;
    
    if(semop(semid,&muvelet,1)<0) // 1 number of sem. operations
        perror("semop");	    
}

void utal(int szemafor, int *bank_accounts_balances, int sender, int recipient, int amount)
{
    szemafor_muvelet(szemafor, -1);
    if (bank_accounts_balances[sender] < amount)
    {
        if (++patience > 1000)
        {
            fprintf(stderr, "person %i could not transfer %i to %i, because (s)he doesn't have enough 💲💲💲\n", sender, amount, recipient);
            patience = 0;
        }
    }
    else
    {
        bank_accounts_balances[sender] -= amount;
        bank_accounts_balances[recipient] += amount;
    }
    szemafor_muvelet(szemafor, 1);
}

int main(int argc, char *argv[])
{
    key_t key = ftok(argv[0], 73);
    if (key == -1)
    {
        perror("ftok error: ");
        return 1;
    }

    int sem = semget(key, 1, S_IRUSR | S_IWUSR | IPC_CREAT);
    if (sem == -1)
    {
        perror("couldn't create sems: ");
        return 1;
    }

    if (semctl(sem, 0, SETVAL, 1) == -1)
    {
        perror("semctl error: ");
        return 1;
    }

    int shm = shmget(key, 100, S_IRUSR | S_IWUSR | IPC_CREAT);
    if (shm == -1)
    {
        perror("couldn't allocate shm: ");
        return 1;
    }

    int *bank_accounts_balances = shmat(shm, NULL, 0);
    if (bank_accounts_balances == (void *)-1)
    {
        perror("couldn't attach shm: ");
        shmctl(shm, IPC_RMID, NULL);
        return 1;
    }

    bank_accounts_balances[0] = 1000000;
    bank_accounts_balances[1] = 1500000;

    printf("the sum of balances before: %i\n", bank_accounts_balances[0] + bank_accounts_balances[1]);
    pid_t fork_ret = fork();
#define RUNTIME_ITERATIONS 600000
    if (fork_ret > 0)
    { // parent
        srand((unsigned int)time(NULL));

        for (int i = 0; i < RUNTIME_ITERATIONS; i++)
        {
            utal(sem, bank_accounts_balances, 0, 1, rand() % 1000);
        }

        wait(NULL);
        printf("the sum of balances after: %i\n", bank_accounts_balances[0] + bank_accounts_balances[1]);
        shmdt(bank_accounts_balances);
        if (shmctl(shm, IPC_RMID, NULL) == -1)
        {
            perror("shmctl error: ");
            return 1;
        }
        if (semctl(sem, 0, IPC_RMID) == -1)
        {
            perror("semctl error: ");
            return 1;
        }
    }
    else if (fork_ret == 0)
    { // child
        for (int i = 0; i < RUNTIME_ITERATIONS; i++)
        {
            utal(sem, bank_accounts_balances, 1, 0, rand() % 1000);
        }

        shmdt(bank_accounts_balances);
    }
    return 0;
}
