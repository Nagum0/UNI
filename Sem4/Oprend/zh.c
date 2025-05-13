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

#define pt(fstr, ...) {printf("[%s] "fstr"\n", whoami ?: "N/A", ##__VA_ARGS__);}
char* whoami = 0;

struct msg {
    long type;
    char text[1024];
};

void dummy_handler(int x) {}

void szemafor_muvelet(int semid, int sem_op) {
    struct sembuf muvelet = {.sem_num = 0, .sem_op = sem_op, .sem_flg = 0};
    semop(semid, &muvelet, 1);
}

int main(int argc, char* argv[]) {
    struct sigaction sa;
    sa.sa_handler = dummy_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    int szolg_vevo_pipe[2]; pipe(szolg_vevo_pipe);

    key_t key = ftok(argv[0], 1);
    int msgid = msgget(key, 0600 | IPC_CREAT);

    int shmid = shmget(key, 1024, IPC_CREAT|S_IRUSR|S_IWUSR);
    char* data = shmat(shmid, NULL, 0);
    
    int semid = semget(key, 1, IPC_CREAT | 0600);
    semctl(semid, 0, SETVAL, 0);

    // GYEREK
    pid_t child1 = fork();
    if (child1 == 0) {
        whoami = "Vevo";
        close(szolg_vevo_pipe[0]);
    
        // 1.
        sleep(1);
        kill(getppid(), SIGUSR1);
        char* kerdes = "Melyik furesz akcios, igy ar ertek aranyban melyik a legjobb valasztas?";
        write(szolg_vevo_pipe[1], kerdes, strlen(kerdes) + 1);
        close(szolg_vevo_pipe[1]);

        // 2.
        struct msg nev_msg;
        msgrcv(msgid, &nev_msg, 1024, 1, 0);
        pt("Furesz neve: %s", nev_msg.text);

        struct msg price_msg;
        msgrcv(msgid, &price_msg, 1024, 2, 0);
        int price = atoi(price_msg.text);
        pt("Furesz ara: %d", price);

        //3. & 4.
        srand(time(NULL));
        int chance = rand() % 2;
        char valasz[2000];

        if (chance == 1) {
            sprintf(valasz, "Kerem a %s lancfureszt %d forintert.", nev_msg.text, price);
        }
        else {
            sprintf(valasz, "Sajnos nem sikerult ennyit osszelocsolni egy fureszert!");
        }

        sleep(1);
        strcpy(data, valasz);
        szemafor_muvelet(semid, 1);

        shmdt(data);

        pt("Befejeztem");

        exit(0);
    }

    // SZULO
    whoami = "Ugyfelszolgalat";
    sigaction(SIGUSR1, &sa, NULL);
    close(szolg_vevo_pipe[1]);
    
    // 1.
    pause();
    char kerdes[100];
    read(szolg_vevo_pipe[0], kerdes, 100);
    close(szolg_vevo_pipe[0]);
    pt("%s", kerdes);

    // 2.
    char* nev = argv[1];
    char* ar = argv[2];
    struct msg nev_msg;
    nev_msg.type = 1;
    strcpy(nev_msg.text, nev);
    sleep(1);

    msgsnd(msgid, &nev_msg, sizeof(nev_msg.text), 0);

    struct msg price_msg;
    price_msg.type = 2;
    strcpy(price_msg.text, ar);
    sleep(1);
    msgsnd(msgid, &price_msg, sizeof(price_msg.text), 0);

    // 3. & 4.
    szemafor_muvelet(semid, -1);
    pt("%s", data);
    
    wait(NULL);
    shmdt(data);
    msgctl(msgid, IPC_RMID, NULL);
    shmctl(shmid, IPC_RMID, NULL);
    semctl(semid, 0, IPC_RMID);

    return 0;
}
