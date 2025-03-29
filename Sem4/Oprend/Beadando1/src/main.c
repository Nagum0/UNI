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

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/nyuszi.h"
#include "../include/cmd.h"

int main(int argc, char* argv[]) {
    nyuszi_list_t* nyuszik = malloc(sizeof(nyuszi_list_t));
    nyuszik->data = NULL;
    nyuszik->len = 0;

    int running = true;

    while (running) {
        int command;
        scanf("%d", &command);

        switch ((cmd_t)command) {
            case EXIT:
                printf("Exiting...\n");
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
            default:
                printf("Unexpected command...\n");
                print_manual();
                break;
        }
    }
    
    nyuszi_list_free(nyuszik);

    return 0;
}
