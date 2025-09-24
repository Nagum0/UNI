#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>

struct p {
    int x;
    int y;
};

int main() {
    int pipefd[2];
    pipe(pipefd);

    pid_t child = fork();

    if (child > 0) {
        close(pipefd[1]);
        struct p p1;
        read(pipefd[0], &p1, sizeof(struct p));
        printf("%d, %d\n", p1.x, p1.y);
        wait(NULL);
    }
    else {
        close(pipefd[0]);
        struct p p1 = { .x = 10, .y = 15};
        write(pipefd[1], &p1, sizeof(struct p));
        exit(0);
    }
}
