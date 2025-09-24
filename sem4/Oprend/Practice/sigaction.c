#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void handler(int sig) {
    printf("Received signal: %d\n", sig);
}

int main() {
    pid_t child = fork();
    struct sigaction sigact;
    sigact.sa_handler = handler;
    sigact.sa_flags = 0;
    sigemptyset(&sigact.sa_mask);

    sigaction(SIGUSR1, &sigact, NULL);

    if (child > 0) {
        sigset_t set;
        sigfillset(&set);
        sigdelset(&set, SIGUSR1);
        printf("PARENT - Waiting for signal from child.\n");
        sigsuspend(&set);

        printf("PARENT - Waiting for child to terminate.\n");
        int status;
        wait(&status);
    }
    else {
        sleep(1);
        printf("CHILD - Sending signal to parent.\n");
        kill(getppid(), SIGUSR1);

        sleep(3);
        printf("CHILD - Terminating.\n");
        exit(0);
    }

    return 0;
}
