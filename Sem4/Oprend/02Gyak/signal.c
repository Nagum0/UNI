#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void handler(int signumber) {
    printf("Signal with number %i has arrived\n",signumber);
}

int main() {
    signal(SIGTERM, handler); //handler = SIG_IGN - ignore the signal (not SIGKILL,SIGSTOP), 
                             //handler = SIG_DFL - back to default behavior 
    signal(SIGUSR1, handler);

    pid_t child = fork();
    if (child > 0) { 
        pause(); //waits till a signal arrive 
        printf("PARENT - Signal arrived\n",SIGTERM);
                // printf("Parent process ended\n");
        
        printf("PARENT - Sending SIGUSR1 to child\n");
        sleep(3);
        kill(child, SIGUSR1);

        int status;
        wait(&status);
    }
    else {
        printf("CHILD - Waits 3 seconds, then send a SIGTERM %i signal\n",SIGTERM);
        sleep(3);
        kill(getppid(), SIGTERM); 
        
        printf("CHILD - Waiting on parent\n");
        pause();
        printf("CHILD - Signal received\n");

        //1. parameter the pid number of process, we send the signal
        // 		if -1, then eacho of the processes of the same uid get the signal
        // 		we kill our bash as well! The connection will close
        //2. parameter the name or number of signal
        printf("CHILD - Child process ended\n");  
    }

    return 0;
}
