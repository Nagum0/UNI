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

int main(int argc, char* argv[]) {
    struct sigaction sigact;
    sigact.sa_handler = dummy_handler;
    sigact.sa_flags = 0;
    sigemptyset(&sigact.sa_mask);

    int komm_rendor_pipe[2];
    pipe(komm_rendor_pipe);
    int rendor_komm_pipe[2];
    pipe(rendor_komm_pipe);

    key_t key = ftok(argv[0], 1);
    int msgid = msgget(key, 0600 | IPC_CREAT);

    int shm_id = shmget(key, 1000, IPC_CREAT | S_IRUSR | S_IWUSR);
    char* shm = shmat(shm_id, NULL, 0);

    int semid = semget(key, 1, IPC_CREAT | 0600);
    semctl(semid, 0, SETVAL, 1);

    pid_t child1 = fork();
    
    if (child1 == 0) {
        whoami = "Rendor alezredes";
        close(komm_rendor_pipe[1]);
        close(rendor_komm_pipe[0]);

        sleep(1);
        pt("Keszen allok!");
        kill(getppid(), SIGUSR1);

        char question1[100];
        read(komm_rendor_pipe[0], question1, 100);

        char* answer1 = "Igen, ha elhagyja a lakast!";
        write(rendor_komm_pipe[1], answer1, strlen(answer1) + 1);

        shmdt(shm);
    }
    else {
        pid_t child2 = fork();

        if (child2 == 0) {
            whoami = "Orszagos tisztfoorvos";

            sleep(2);
            pt("Keszen allok!");
            kill(getppid(), SIGUSR1);

            char* text = "A maszk viselese valoban nagyon fontos!";
            struct msg answer2;
            answer2.type = 1;
            strncpy(answer2.text, text, strlen(text) + 1);
            msgsnd(msgid, &answer2, sizeof(answer2.text), 0);

            szemafor_muvelet(semid, -1);
            int fertozottek_szama = 100;
            char answer3[100];
            sprintf(answer3, "A napi uj fertozottek szama: %d", fertozottek_szama);
            memcpy(shm, answer3, 100);
            szemafor_muvelet(semid, 1);

            shmdt(shm);
        }
        // PARENT
        else {
            whoami = "Kommunikacios tiszt";
            close(komm_rendor_pipe[0]);
            close(rendor_komm_pipe[1]);
            sigaction(SIGUSR1, &sigact, NULL);
            
            pause();
            pause();
            pt("A resztvevok elfoglaltak a helyuket a podiumon.");

            char* question1 = "Maszk viselese kotelezo minden boltban?";
            pt("Kerdes a rendor alezredesnek: %s", question1);
            write(komm_rendor_pipe[1], question1, strlen(question1) + 1);

            char answer1[100];
            read(rendor_komm_pipe[0], answer1, 100);
            pt("Valasz a rendor alezredestol: %s", answer1);

            struct msg answer2;
            msgrcv(msgid, &answer2, 1024, 1, 0);
            pt("Valasz az orszagos tisztfoorvostol: %s", answer2.text);
            
            szemafor_muvelet(semid, -1);
            pt("Valasz az orszagos tisztfoorvostol: %s", shm);
            szemafor_muvelet(semid, 1);

            msgctl(msgid, IPC_RMID, NULL);
            shmdt(shm);
            shmctl(shm_id, IPC_RMID, NULL);
            semctl(semid, 0, IPC_RMID);

            wait(NULL);
            wait(NULL);
        }
    }
        
    return 0; 
}
