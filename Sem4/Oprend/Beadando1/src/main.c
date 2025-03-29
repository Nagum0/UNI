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
#include <stdbool.h>
#include <string.h>
#include "../include/nyuszi.h"

#define INPUT_BUFFER_SIZE 1024

void flush_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/*
 *
 * ------- USER COMMANDS -------
 *
 * */
typedef enum {
    EXIT = 1,
    CHANGE_NAME,
    CHANGE_VERS,
    CHANGE_EGGS,
    LIST,
    SIGN_UP,
    DELETE_NYUSZI,
    MAN,
} cmd_t;

void print_manual() {
    printf("-------- MANUAL --------\n");
    printf("%-22s %d\n", "EXIT", 1);
    printf("%-22s %d\n", "CHANGE NAME", 2);
    printf("%-22s %d\n", "CHANGE POEM", 3);
    printf("%-22s %d\n", "CHANGE EGGS", 4);
    printf("%-22s %d\n", "LIST PARTICIPANTS", 5);
    printf("%-22s %d\n", "SIGN UP A PARTICIPANT", 6);
    printf("%-22s %d\n", "DELETE PARTICIPANT", 7);
    printf("%-22s %d\n", "MANUAL", 8);
}

void sign_up_handler() {
    flush_stdin();

    nyuszi_t nyuszi = {0};

    printf("Participant name: ");
    char name_buffer[LEN_NAME];
    if (fgets(name_buffer, LEN_NAME, stdin) == NULL) {
        fprintf(stderr, "Error while signing up new participant...\n");
        exit(1);
    }
    nyuszi_set_name(&nyuszi, name_buffer);
    flush_stdin();

    printf("Participant poem: ");
    char poem_buffer[LEN_POEM];
    if (fgets(poem_buffer, LEN_POEM, stdin) == NULL) {
        fprintf(stderr, "Error while signing up new participant...\n");
        exit(1);
    }
    nyuszi_set_poem(&nyuszi, poem_buffer);
    flush_stdin();

    printf("Participant eggs: ");
    scanf("%d", &nyuszi.eggs);

    char* n_str = nyuszi_to_str(&nyuszi);
    printf("%s\n", n_str);
    free(n_str);
}

int main(int argc, char* argv[]) {
    int running = true;

    while (running) {
        int command;
        scanf("%d", &command);

        switch ((cmd_t)command) {
            case EXIT:
                printf("Exiting...\n");
                exit(0);
            case CHANGE_NAME:
                break;
            case LIST:
                break;
            case SIGN_UP:
                sign_up_handler();
                break;
            case MAN:
                print_manual();
                break;
            default:
                printf("Unexpected command...\n");
                print_manual();
                break;
        }

        flush_stdin();
    }

    return 0;
}
