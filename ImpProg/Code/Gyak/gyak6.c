#include <stdio.h>
#include <string.h>

#define HEIGHT 10
#define WIDTH 10

// Misc.
extern void init(int table[HEIGHT][WIDTH]);
extern void printTable(int table[HEIGHT][WIDTH]);

// Movement.
extern int *getPlayerPos(int table[HEIGHT][WIDTH]);
extern void movePlayer(int table[HEIGHT][WIDTH], int x, int y);

int main(void) {
    int table[HEIGHT][WIDTH];
    init(table);
    movePlayer(table, 1, -1);

    return 0;
}

void movePlayer(int table[HEIGHT][WIDTH], int x, int y) {
    int *currectPos = getPlayerPos(table);

    memset(table, 0, sizeof(int) * HEIGHT * WIDTH);

    table[currectPos[0] + y][currectPos[1] + x] = 1;
    printTable(table);
}

int *getPlayerPos(int table[HEIGHT][WIDTH]) {
    static int playerCoords[2];

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (table[i][j] == 1) {
                playerCoords[0] = i;
                playerCoords[1] = j;
                break;
            }
        }
    }

    return playerCoords;
}

void printTable(int table[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}

void init(int table[HEIGHT][WIDTH]) {
    memset(table, 0, sizeof(int) * HEIGHT * WIDTH);
    table[4][4] = 1;
}