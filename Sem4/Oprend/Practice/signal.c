#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handle_signal(int sig) {
    printf("HANDLER - Signal: %d\n", sig);
}

int main() {
    signal(SIGTERM, handle_signal);
    
    pid_t child = fork();

    if (child > 0) {
        printf("PARENT - Parent waiting for signal from child...\n");
        pause();
        printf("PARENT - Received signal from child.\n");
        
        sleep(1);
        printf("PARENT - Sending SIGTERM to child.\n");
        kill(child, SIGTERM);

    }
    else {
        sleep(1);
        printf("CHILD - Sending SIGTERM to parent.\n");
        kill(getppid(), SIGTERM);

        sleep(1);
        printf("CHILD - Waiting for signal from parent...\n");
        pause();
        printf("CHILD - Received signal from parent.\n");
    }

    return 0;
}
