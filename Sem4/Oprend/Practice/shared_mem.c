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

int main() {
    // SHARED MEMORY SETUP
    key_t shm_key = ftok("mem", 65);
    int shm_id = shmget(shm_key, 100, IPC_CREAT | S_IRUSR | S_IWUSR);
    char* shm = shmat(shm_id, NULL, 0);
    
    // SIGACTION SETUP
    struct sigaction sigact;
    sigact.sa_handler = dummy_handler;
    sigact.sa_flags = 0;
    sigemptyset(&sigact.sa_mask);

    // FORKING
    pid_t child = fork();

    if (child > 0) {
        whoami = "parent";
        sigaction(SIGUSR1, &sigact, NULL);
                
        pt("Waiting for SIGUSR1 from child.");
        pause();
        pt("Received signal. Writing data to shared memory.");
        char* data = "EZ 4 ENCE ENCE ENCE PUTERPUTERBELL";
        memcpy(shm, data, strlen(data) + 1);
        kill(child, SIGUSR2);
        wait(NULL);

        shmdt(shm);
        shmctl(shm_id, IPC_RMID, NULL);
    }
    else {
        whoami = "child";
        sigaction(SIGUSR2, &sigact, NULL);
        
        sleep(1);
        pt("Sending SIGUSR1 to parent.");
        kill(getppid(), SIGUSR1);
        pt("Waiting for parent to write into shared memory.");
        pause();
        pt("Received signal. Read data: %s", shm);
       
        shmdt(shm);
    }

    return 0;
}
