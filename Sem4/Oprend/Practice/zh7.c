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

void handler(int signumber, siginfo_t* info, void* nonused) {

}

int main() {
    int pid_pipe[2];
    pipe(pid_pipe);

    struct sigaction sigact;
    sigact.sa_sigaction = handler;
    sigact.sa_flags = SA_SIGINFO;
    sigemptyset(&sigact.sa_mask);

    pid_t child1 = fork();

    if (child1 == 0) {
        whoami = "Child 1";
        pt("PID: %d", getpid());

        close(pid_pipe[0]);
        pid_t my_pid = getpid();
        write(pid_pipe[1], &my_pid, sizeof(pid_t));
        close(pid_pipe[1]);

    }
    else {
        pid_t child2 = fork();

        if (child2 == 0) {
            whoami = "Child 2";
            pt("PID: %d", getpid());
            
            close(pid_pipe[1]);
            pid_t sibling_pid;
            read(pid_pipe[0], &sibling_pid, sizeof(pid_t));
            close(pid_pipe[0]);

            pt("Sibling pid: %d", sibling_pid);

        }
        else {
            whoami = "Parent";
            pt("PID: %d", getpid());

            wait(NULL);
            wait(NULL);
        }
    }
}
