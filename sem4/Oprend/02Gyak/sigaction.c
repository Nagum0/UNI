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
    struct sigaction sigact;
    sigact.sa_handler=handler; //SIG_DFL,SIG_IGN
    sigemptyset(&sigact.sa_mask); //during execution of handler these signals will be blocked plus the signal    
                                  //now only the arriving signal, SIGTERM will be blocked
    sigact.sa_flags=0; //nothing special behaviour
    sigaction(SIGTERM,&sigact,NULL);
    sigaction(SIGUSR1,&sigact,NULL);

    pid_t child=fork();
    if (child>0)
    {
        sigset_t sigset;
        sigfillset(&sigset);
        sigdelset(&sigset,SIGTERM);
        sigsuspend(&sigset);
        // like pause() - except it waits only for signals not given in sigset
        //others will be blocked
        printf("The program comes back from suspending\n");
        int status;
        wait(&status);
        printf("Parent process ended\n");
    }
    else 
    {
        printf("Waits 3 seconds, then send a SIGUSR %i signal (it is not waited for by suspend) - so the suspend continues waiting\n", SIGUSR1);
        sleep(3);
        kill(getppid(),SIGUSR1);
        printf("Waits 3 seconds, then send a SIGTERM %i signal (it is waited for by suspend)\n",SIGTERM);
        sleep(3);
        kill(getppid(),SIGTERM);
        printf("Child process ended\n");  
    }
    return 0;
}
