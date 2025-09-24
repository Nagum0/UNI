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

int main(int argc, char* argv[]) {
    // PIPE
    int pipefd[2];
    pipe(pipefd);

    // SIGACTION
    struct sigaction sigact;
    sigact.sa_handler = dummy_handler;
    sigact.sa_flags = 0;
    sigemptyset(&sigact.sa_mask);

    pid_t gy1 = fork();

    if(gy1){
        whoami = "parent";
        close(pipefd[0]);
        sigaction(SIGUSR1, &sigact, NULL);

        pt("Waiting for child to send SIGUSR1.");
        pause();

        pt("SIGUSR1 received. Sending message through pipe.");
        char* message = "Hello there my child stop playing so much CS2.";
        write(pipefd[1], message, strlen(message) + 1);
        kill(gy1, SIGUSR2);
        
        close(pipefd[1]);
        int status;
        wait(&status);
    }
    else{
        whoami = "child";
        close(pipefd[1]);
        sigaction(SIGUSR2, &sigact, NULL);
    
        sleep(1);
        pt("Sending SIGUSR1 to parent.");
        kill(getppid(), SIGUSR1);
    
        pause();
        pt("SIGUSR2 received. Reading message from pipe.");
        char buffer[100];
        read(pipefd[0], buffer, sizeof(buffer));
        pt("Received message: %s", buffer);

        close(pipefd[0]);
        exit(0);
    }

    return 0;
}
