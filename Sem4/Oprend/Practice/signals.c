#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handler(int sig) {
    printf("caught sigint\n");
}

int main() {
    pid_t child = fork();

    if (child > 0) {
        // PARENT
        sleep(1);
        kill(child, SIGINT);
    }
    else {
        // CHILD
        signal(SIGINT, handler);
        pause();
    }

    return 0; 
}
