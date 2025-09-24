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
#include <stdbool.h>
#include "../include/nyuszi.h"
#include "../include/cmd.h"

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
                winner_handler(nyuszik);
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
            case SAVE:
                save_handler("data.txt", nyuszik);
                break;
            default:
                printf("Unexpected command...\n");
                print_manual();
                break;
        }
    }
    
    nyuszi_list_free(nyuszik);
    // printf("-- main: nyuszik freed\n"); // DEBUG

    return 0;
}
