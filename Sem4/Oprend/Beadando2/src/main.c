/*
 * Itt a tavasz, a nyuszik is készülnek a "Húsvéti Locsolókirály" választásra. A nyuszi fiúk között versenyt szervez "Főnyuszi", az lesz a "Locsolókirály", 
 * aki a legszebb locsolóverset tudja elmondani. Pl.  "Piros tojás fehér nyuszi, locsolásért jár egy puszi!" 
 * A locsoló versike mellett tároljuk a nyuszi fiú nevét (pl Tapsi Füles) és a versikéért kapott tojások számát. 
 * Aki a locsolás során a legtöbb piros tojást gyűjti össze a nyuszi lányoktól az lesz a király. 
 * A versenyre jelentkezni kell.  A jelentkezéskor meg kell adni nyuszinak a nevét, a locsoló versikét. A tojások száma jelentkezéskor 0. 
 *
 * A jelentkezők adatait fájlban tároljuk, az adatfelvételen túl legyen lehetőségünk az adatokon módosítani, törölni és teljes listát készíteni a jelentkezőkről. 
 *
 * Készítsen C nyelvű programot ami ezt a feladatot megoldja, a megoldásnak vagy az opsys.inf.elte.hu kiszolgálón, 
 * vagy egy hozzá hasonló Linux rendszeren kell futnia. A megoldást a beadási határidőt követő héten be kell mutatni a gyakorlatvezetőnek. 
 */

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
#include "../include/nyuszi.h"
#include "../include/cmd.h"

#define pt(fstr, ...) {printf("[%s] "fstr"\n", whoami ?: "N/A", ##__VA_ARGS__);}
char* whoami = 0;

void dummy_handler(int sig) {}

int main(int argc, char* argv[]) {
    print_manual();

    // printf("-- main: started\n"); // DEBUG
    nyuszi_list_t* nyuszik = load_from_file("data.txt");
    // printf("-- main: nyuszik loaded\n"); // DEBUG

    int running = true;

    while (running) {
        printf("Command: ");
        int command;
        scanf("%d", &command);

        switch ((cmd_t)command) {
            case EXIT:
                running = false;
                break;
            case CHANGE_NAME:
                change_name_handler(nyuszik);
                break;
            case CHANGE_VERS:
                change_poem_handler(nyuszik);
                break;
            case CHANGE_EGGS:
                change_eggs_handler(nyuszik);
                break;
            case LIST:
                list_handler(nyuszik);
                break;
            case SIGN_UP:
                sign_up_handler(nyuszik);
                break;
            case DELETE_NYUSZI:
                delete_handler(nyuszik);
                break;
            case MAN:
                print_manual();
                break;
            case SAVE:
                save_handler("data.txt", nyuszik);
                break;
            default:
                printf("Unexpected command...\n");
                print_manual();
                break;
        }
    }
    
    printf("The tournament is starting!\n");
    
    for (size_t i = 0; i < nyuszik->len; ++i) {
        if (nyuszik->data[i] == NULL)
            continue;

        nyuszi_t* nyuszi = nyuszik->data[i];

        int pipefd[2];
        pipe(pipefd);

        struct sigaction sigact;
        sigact.sa_handler = dummy_handler;
        sigact.sa_flags = 0;
        sigemptyset(&sigact.sa_mask);

        pid_t child = fork();

        if (child > 0) {
            whoami = "FŐNYUSZI";
            sigaction(SIGUSR1, &sigact, NULL);
            close(pipefd[1]);

            // Parent waits for child signal
            pause();

            // Give time for child to write into the pipe
            sleep(1);
            int egg_count;
            read(pipefd[0], &egg_count, sizeof(int));
        
            // Update data
            nyuszi_list_update_eggs(nyuszik, nyuszi->name, egg_count);

            wait(NULL);
        }
        else {
            whoami = nyuszi->name;
            close(pipefd[0]);
            
            srand(time(NULL));
            kill(getppid(), SIGUSR1);
            pt("%s", nyuszi->poem);

            // Get eggs
            int egg_count = (rand() % 19) + 1;
            pt("Received eggs: %d", egg_count);
            write(pipefd[1], &egg_count, sizeof(egg_count));

            exit(0);
        }
    }
    
    save_handler("data.txt", nyuszik);
    winner_handler(nyuszik);
    nyuszi_list_free(nyuszik);

    return 0;
}
