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

pid_t child1;
pid_t child2;
char* c1_msg = NULL;
char* c2_msg = NULL;
char* x = "x";
char* y = "y";

#define pt(fstr, ...) {printf("[%s] "fstr"\n", whoami ?: "N/A", ##__VA_ARGS__);}

char* whoami = 0;

void c1_handler(int signumber, siginfo_t* info, void* nonused) {
    c1_msg = info->si_value.sival_ptr;   
}

void c2_handler(int signumber, siginfo_t* info, void* nonused) {
    c2_msg = info->si_value.sival_ptr;   
}

int main() {
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);

    whoami = "Parent";

    child1 = fork();
    if (child1 == 0) {
        whoami = "1";
        sa.sa_sigaction = c1_handler;
        sigaction(SIGUSR1, &sa, NULL);

        pause();
        pt("Message: %s", c1_msg);

        exit(0);
    }


    child2 = fork();
    if (child2 == 0) {
        whoami = "2";
        sa.sa_sigaction = c2_handler;
        sigaction(SIGUSR1, &sa, NULL);

        pause();
        pt("Message: %s", c2_msg);

        exit(0);
    }
 
    sleep(2);

    union sigval c1;
    c1.sival_ptr = x;
    sigqueue(child1, SIGUSR1, c1);
    
    sleep(2);

    union sigval c2;
    c2.sival_ptr = y;
    sigqueue(child2, SIGUSR1, c2);

    wait(NULL);
    wait(NULL);
}
