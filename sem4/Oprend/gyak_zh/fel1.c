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
#define pt(fstr, ...)                                              \
    {                                                              \
        printf("[%s] " fstr "\n", whoami ?: "N/A", ##__VA_ARGS__); \
    }
char *whoami = 0;

void dummy_handler(int x) {}

void do_not_kill_me(int signum) { signal(signum, dummy_handler); }

void szemafor_muvelet(int semid, int sem_op)
{
    struct sembuf muvelet = {.sem_num = 0, .sem_op = sem_op, .sem_flg = 0};
    semop(semid, &muvelet, 1);
}

int main(int argc, char *argv[])
{
    do_not_kill_me(SIGUSR1);

    int paciensek = atoi(argv[1]);
    pt("paciensek: %i", paciensek);

    int ursulanak = paciensek / 2;
    int csormesterek = paciensek - ursulanak;

    int bubo_to_csormester[2];
    int bubo_to_ursula[2];
    pipe(bubo_to_csormester);
    pipe(bubo_to_ursula);

    pid_t gy1 = fork();
    if (gy1)
    {
        pid_t gy2 = fork();
        if(gy2){
            whoami = "Dr. Bubo";
            close(bubo_to_csormester[0]);
            close(bubo_to_ursula[0]);
            
            pause();
            pause();
            
            write(bubo_to_csormester[1], &csormesterek, sizeof(csormesterek));
            write(bubo_to_ursula[1], &ursulanak, sizeof(ursulanak));
            close(bubo_to_csormester[1]);
            close(bubo_to_ursula[1]);

            wait(0);
            wait(0);
        }else{
            whoami = "Ursula";
            close(bubo_to_csormester[0]);
            close(bubo_to_csormester[1]);
            close(bubo_to_ursula[1]);

            sleep(1);
            kill(getppid(), SIGUSR1);

            int oltasra_varok;
            read(bubo_to_ursula[0], &oltasra_varok, sizeof(oltasra_varok));
            close(bubo_to_ursula[0]);
            pt("ennyi allatot kell beoltanom: %i", oltasra_varok);
        }
        pt("kilepes");
    }
    else
    {
        whoami = "Csormester";
        close(bubo_to_ursula[0]);
        close(bubo_to_ursula[1]);
        close(bubo_to_csormester[1]);

        sleep(2);
        kill(getppid(), SIGUSR1);
        
        int oltasra_varok;
        read(bubo_to_csormester[0], &oltasra_varok, sizeof(oltasra_varok));
        close(bubo_to_csormester[0]);
        pt("ennyi allatot kell beoltanom: %i", oltasra_varok);

        pt("kilepes");
    }

    return 0;
}
