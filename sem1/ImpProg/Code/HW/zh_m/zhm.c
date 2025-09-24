#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HEIGHT 10
#define WIDTH 10

// -- INIT

int init(int table[HEIGHT][WIDTH], int ships[4]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            table[i][j] = 0;
        }
    }

    for (int i = 0; i < 4; i++) {
        ships[i] = 0;
    }
}

// -- PRINTTABLE

void printTable(int table[HEIGHT][WIDTH]) {
    printf("===================\n");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }

    printf("===================\n");
}

// -- SUBMIT

// Visszaadja integerben az oszlopszamot.
int returnCol(char col) {
    switch (col) {
        default:
            return -1;
            break;
        case 'A':
            return 0;
            break;
        case 'B':
            return 1;
            break;
        case 'C':
            return 2;
            break;
        case 'D':
            return 3;
            break;
        case 'E':
            return 4;
            break;
        case 'F':
            return 5;
            break;
        case 'G':
            return 6;
            break;
        case 'H':
            return 7;
            break;
        case 'I':
            return 8;
            break;
        case 'J':
            return 9;
            break;
    }
}

// Visszaadja integerben a sorszamot.
int returnRow(char *poz) {
    if (strlen(poz) == 2) {
        return (int) (poz[1] - '0') - 1;
    }
    else if (strlen(poz) == 3) {
        char digits[] = {poz[1], poz[2]};
        int row = atoi(digits) - 1;

        if (row >= 10) {
            return -1;
        }
        else {
            return row;
        }
    }
    else {
        return -2;
    }
}

int checkShipLength(int len) {
    if (1 < len && len < 6) {
        return 0;
    }
    else {
        return 1;
    }
}

void submit(int table[HEIGHT][WIDTH], int ships[4], char *poz, int shipLength, char axis) {
    // Hajo hosszanak ellenorzese.
    if (checkShipLength(shipLength) == 1) {
        printf("Nem felel meg a hajo hossza! {%d} \n", shipLength);
        return;
    }

    // -- Sorszam
    int row = returnRow(poz);

    if (row == -1) {
        printf("Tablan kivuli sorszam!\n");
        return;
    }
    else if (row == -2) {
        printf("Helytelen kezdo pozicio!\n");
        return;
    }

    // -- Oszlopszam
    int col = returnCol(poz[0]);

    if (col == -1) {
        printf("Tablan kivuli oszlopszam!\n");
        return;
    }

    for (int i = 0; i < shipLength; i++) {
        // Hajo horizontalisan elhelyezve.
        if (axis == '_') {
            if (table[row][col + i] == 0) {
                table[row][col + i] = shipLength;
            }
            else {
                printf("Foglalt a hely! [%d;%d] \n", row, col);
                return;
            }
        }
        // Hajo vertikalisan elhelyezve.
        else if (axis == '|') {
            if (table[row + i][col] == 0) {
                table[row + i][col] = shipLength;
            }
            else {
                printf("Foglalt a hely! [%d;%d] \n", row, col);
                return;
            }
        }
        else {
            printf("Ismeretlen axis!\n");
            return;
        }
    }


}

// -- MAIN

int main(void) {
    int table[HEIGHT][WIDTH];
    int numOfShips[4];

    init(table, numOfShips);
    submit(table, numOfShips, "A1", 3, '|');
    submit(table, numOfShips, "J1", 6, '|');
    printTable(table);

    return 0;
}