#include <bits/pthreadtypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
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

    int elado_vasarlo1_pipe[2];
    pipe(elado_vasarlo1_pipe);
    int elado_vasarlo2_pipe[2];
    pipe(elado_vasarlo2_pipe);

    key_t key = ftok("x", 1);
    int msgid = msgget(key, 0600 | IPC_CREAT);
    
    char* arulista[] = { "kenyer", "alma", "cola", "pepsi", "sonka", "keksz" };
    size_t arulista_len = sizeof(arulista) / sizeof(char*);

    // Vasarlo 1
    key_t v1_key = ftok("y", 2);
    int vasarlo1_shmid = shmget(v1_key, 100, IPC_CREAT | S_IRUSR | S_IWUSR);
    char* vasarlo1_shm = shmat(vasarlo1_shmid, NULL, 0);
    int v1_semid = semget(v1_key, 1, IPC_CREAT | 0600);
    semctl(v1_semid, 0, SETVAL, 1);

    // Vasarlo 2
    key_t v2_key = ftok("z", 3);
    int vasarlo2_shmid = shmget(v2_key, 100, IPC_CREAT | S_IRUSR | S_IWUSR);
    char* vasarlo2_shm = shmat(vasarlo2_shmid, NULL, 0);
    int v2_semid = semget(v2_key, 1, IPC_CREAT | 0600);
    semctl(v2_semid, 0, SETVAL, 1);

    pid_t child1 = fork();

    if (child1 == 0) {
        whoami = "Vasarlo 1";
        close(elado_vasarlo1_pipe[1]);
        
        sleep(1);
        pt("Bemehetek?");
        kill(getppid(), SIGUSR1);
        char msg[100];
        read(elado_vasarlo1_pipe[0], msg, 100);
        pt("Kapott uzenet: %s", msg);

        struct msg msg2;
        msgrcv(msgid, &msg2, 1024, 1, 0);
        pt("%s", msg2.text);

        szemafor_muvelet(v1_semid, -1);
        srand(getpid() ^ time(NULL));
        char* aru = arulista[rand() % arulista_len];
        memcpy(vasarlo1_shm, aru, strlen(aru) + 1);
        pt("%s, %s", aru, vasarlo1_shm);
        szemafor_muvelet(v1_semid, 1);
        
        shmdt(vasarlo1_shm);
    }
    else {
        pid_t child2 = fork();

        if (child2 == 0) {
            whoami = "Vasarlo 2";
            close(elado_vasarlo2_pipe[1]);

            sleep(2);
            pt("Bemehetek?");
            kill(getppid(), SIGUSR1);
            char msg[100];
            read(elado_vasarlo2_pipe[0], msg, 100);
            pt("Kapott uzenet: %s", msg);

            struct msg msg2;
            msgrcv(msgid, &msg2, 1024, 2, 0);
            pt("%s", msg2.text);

            szemafor_muvelet(v2_semid, -1);
            srand(getpid() ^ time(NULL));
            char* aru = arulista[rand() % arulista_len];
            memcpy(vasarlo2_shm, aru, strlen(aru) + 1);
            pt("%s, %s", aru, vasarlo2_shm);
            szemafor_muvelet(v2_semid, 1);

            shmdt(vasarlo2_shm);
        }
        else {
            whoami = "Elado";
            sigaction(SIGUSR1, &sigact, NULL);
            close(elado_vasarlo1_pipe[0]);
            close(elado_vasarlo2_pipe[0]);

            pause();
            pause();
            char* msg = "Kinyittam, belehet jonni!";
            write(elado_vasarlo1_pipe[1], msg, strlen(msg) + 1);
            write(elado_vasarlo2_pipe[1], msg, strlen(msg) + 1);

            sleep(1);
            struct msg msg2;
            msg2.type = 1;
            char* text = "Jo napot kivanok!";
            strncpy(msg2.text, text, strlen(text) + 1);
            msgsnd(msgid, &msg2, sizeof(msg2.text), 0);
            msg2.type = 2;
            msgsnd(msgid, &msg2, sizeof(msg2.text), 0);
            
            sleep(2);
            szemafor_muvelet(v1_semid, -1);
            pt("Vas 1: %s - %p", vasarlo1_shm, vasarlo1_shm);
            szemafor_muvelet(v1_semid, 1);
            szemafor_muvelet(v2_semid, -1);
            pt("Vas 2: %s - %p", vasarlo2_shm, vasarlo2_shm);
            szemafor_muvelet(v2_semid, 1);

            semctl(v1_semid, 0, IPC_RMID);
            semctl(v2_semid, 0, IPC_RMID);
            shmdt(vasarlo1_shm);
            shmdt(vasarlo2_shm);
            shmctl(vasarlo1_shmid, IPC_RMID, NULL);
            shmctl(vasarlo2_shmid, IPC_RMID, NULL);

            wait(NULL);
            wait(NULL);
        }
    }

    return 0;
}
