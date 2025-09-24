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

void dummy_handler(int x){}

char* whoami = 0;

struct sembuf lock = { 0, -1, 0 };
struct sembuf unlock = { 0, 1, 0 };

int main(int argc, char* argv[]) {
    // SHARED MEMORY
    key_t key = ftok(argv[0], 1);
    int shmid = shmget(key, 100, IPC_CREAT | 0600);
    char* shm = shmat(shmid, NULL, 0);
    
    // SEMAPHORE
    int semid = semget(key, 1, IPC_CREAT | 0600);
    semctl(semid, 0, SETVAL, 1);

    // FORKING
    pid_t child = fork();

    if (child > 0) {
        whoami = "parent";

        semop(semid, &lock, 1);
        pt("Writing data to shared memory.");
        char* data = "EZ 4 ENCE ENCE ENCE PUTTERPUTTERBELL";
        strncpy(shm, data, strlen(data) + 1);
        semop(semid, &unlock, 1);
        
        semop(semid, &lock, 1);
        pt("Reading data from shared memory: %s", shm);
        semop(semid, &unlock, 1);
    
        wait(NULL);
        shmdt(shm);
        shmctl(shmid, IPC_RMID, NULL);
        semctl(semid, 0, IPC_RMID);
    }
    else {
        whoami = "child";

        semop(semid, &lock, 1);
        pt("Reading data from shared memory: %s", shm);
        pt("Writing new data to shared memory.");
        memset(shm, 0, 100);
        char* data = "IM ADDICTED TO CS2";
        strncpy(shm, data, strlen(data) + 1);
        semop(semid, &unlock, 1);

        shmdt(shm);
    }

    return 0;
}
