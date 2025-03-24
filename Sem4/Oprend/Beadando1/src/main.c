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

#include "../headers/nyuszi.h"
#include <stdio.h>
#include <stdlib.h>

void flush_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

typedef enum {
    EXIT = 1,
    CHANGE_NAME,
    CHANGE_VERS,
    CHANGE_EGGS,
    LIST,
    DELETE_NYUSZI,
} cmd_t;

int main(int argc, char* argv[]) {
    int running = 1;

    while (running) {
        int command;
        scanf("%d", &command);

        switch ((cmd_t)command) {
            case EXIT:
                printf("Bye bye!\n");
                exit(0);
            default:
                printf("Dunno' what you mean...\n");
                break;
        }

        flush_stdin();
    }

    return 0;
}
