#include <bits/pthreadtypes.h>
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

void dummy_handler(int x) {}

void szemafor_muvelet(int semid, int sem_op) {
    struct sembuf muvelet = {.sem_num = 0, .sem_op = sem_op, .sem_flg = 0};
    semop(semid, &muvelet, 1);
}

struct msg {
    long type;
    char text[1024];
};

int main(int agrc, char* argv[]) {
    struct sigaction sigact;
    sigact.sa_handler = dummy_handler;
    sigact.sa_flags = 0;
    sigemptyset(&sigact.sa_mask);
    
    key_t out_key = ftok(argv[0], getpid());
    int out_shmid = shmget(out_key, 100, IPC_CREAT | S_IRUSR | S_IWUSR);
    char* out_shm = shmat(out_shmid, NULL, 0);

    int semid = semget(out_key, 1, IPC_CREAT | 0600);
    semctl(semid, 0, SETVAL, 1);

    pid_t child = fork();

    if (child == 0) {
        int felhasznalo_app_pipe[2];
        pipe(felhasznalo_app_pipe);
        
        key_t key = ftok("x", getpid());
        int shmid = shmget(key, 100, IPC_CREAT | S_IRUSR | S_IWUSR);
        char* shm = shmat(shmid, NULL, 0);

        int msgid = msgget(key, 0600 | IPC_CREAT);

        pid_t gchild = fork();

        if (gchild == 0) {
            whoami = "App";
            close(felhasznalo_app_pipe[1]);
            
            kill(getppid(), SIGUSR1);
            char login[100];
            read(felhasznalo_app_pipe[0], login, 100);
            pt("%s", login);

            char* fenykep = "Ez a fenykep.";
            pt("%s", fenykep);
            memcpy(shm, fenykep, strlen(fenykep) + 1);

            struct msg date;
            msgrcv(msgid, &date, 100, 1, 0);
            pt("%s", date.text);

            szemafor_muvelet(semid, -1);
            memcpy(out_shm, date.text, strlen(date.text) + 1);
            szemafor_muvelet(semid, 1);

            shmdt(shm);
        }
        else {
            whoami = "Felhasznalo";
            sigaction(SIGUSR1, &sigact, NULL);
            close(felhasznalo_app_pipe[0]);

            pause();
            char* login = "Zeki, 0000";
            write(felhasznalo_app_pipe[1], login, strlen(login) + 1);
            
            sleep(1);
            srand(time(NULL));
            int chance = rand() % 2;

            struct msg date;
            date.type = 1;
            char text[100];
            if (chance) {
                sprintf(text, "%d 2025.05.02", rand() % 25);
                strncpy(date.text, text, strlen(text) + 1);
                msgsnd(msgid, &date, 100, 0);
            }
            else {
                char* msg = "Rossz a kep.";
                strncpy(date.text, msg, strlen(msg) + 1);
                msgsnd(msgid, &date, 100, 0);
            }
            
            shmdt(shm);
            shmctl(shmid, IPC_RMID, NULL);
            msgctl(msgid, IPC_RMID, NULL);

            wait(NULL);
        }
    }
    else {
        whoami = "Szolgaltato";
        
        sleep(2);
        szemafor_muvelet(semid, -1);
        pt("%s", out_shm);
        szemafor_muvelet(semid, 1);

        shmdt(out_shm);
        shmctl(out_shmid, IPC_RMID, NULL);
        semctl(semid, 0, IPC_RMID);

        wait(NULL);
    }

    return 0;
}
