#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int HEIGHT = 6;
const int WIDTH = 7;

int **init();
void printTable(int **table);
void submit(int **table, char colChar, int player);

int main(int argc, char *argv[]) {
    char *rounds = argv[1];
    int **table = init();
    
    for (int i = 1; i <= strlen(rounds); i++) {
        if (i % 2 == 0) {
            submit(table, rounds[i - 1], 2);
        }
        else {
            submit(table, rounds[i - 1], 1);
        }

        /* 
            EVAULATE !!!
            01:40:58
        */
       printTable(table);
    }

    // FREE
    for (int i = 0; i < HEIGHT; i++) {
        free(table[i]);
    }
    free(table);

    return 0;
}

int **init() {
    int **table = calloc(HEIGHT, sizeof(int *));

    for (int i = 0; i < HEIGHT; i++) {
        table[i] = calloc(WIDTH, sizeof(int));
    }

    return table;
}

void printTable(int **table) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", table[i][j]);
        }

        printf("\n");
    } 
}

void submit(int **table, char colChar, int player) {
    int col;

    switch (colChar) {
        case 'A':
            col = 0;
            break;
        case 'B':
            col = 1;
            break;
        case 'C':
            col = 2;
            break;
        case 'D':
            col = 3;
            break;
        case 'E':
            col = 4;
            break;
        case 'F':
            col = 5;
            break;
        case 'G':
            col = 6;
            break;
        default:
            printf("Non existent column: [%c]\n", colChar);
            break;
    }

    if (table[0][col] != 0) {
        printf("The column [%c] is full! Player: [%d]\n", colChar, player);
    }
    else {
        for (int i = 1; i <= HEIGHT; i++) {
            if (table[HEIGHT - i][col] == 0) {
                table[HEIGHT - i][col] = player;
                break;
            }
        }
    }
}