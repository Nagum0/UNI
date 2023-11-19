#include <stdio.h>
#include <string.h>

#define HEIGHT 10
#define WIDTH 10

#define BUFFER_SIZE 100

extern void init(int table[HEIGHT][WIDTH]);
extern void printTable(int table[HEIGHT][WIDTH]);
extern void movePlayer(int table[HEIGHT][WIDTH], int x, int y);
extern int charToInt(char c);

int main(void) {
    int table[HEIGHT][WIDTH];
    init(table);
    
    char buffer[BUFFER_SIZE];
    int loop = 0;

    do {
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (strcmp(buffer, ":m\n") == 0) {
                char coords[4];

                if (fgets(coords, sizeof(coords), stdin) != NULL) {
                    movePlayer(table, charToInt(coords[0]), charToInt(coords[2]));
                }
            }
            else if (strcmp(buffer, ":q\n") == 0) {
                loop = 1;
            }
            else {
                continue;
            }
        }

    } while (loop == 0);

    return 0;
}

void movePlayer(int table[HEIGHT][WIDTH], int x, int y) {
    memset(table, 0, sizeof(int) * HEIGHT * WIDTH);
    table[y - 1][x - 1] = 1;
    printTable(table);
}

int charToInt(char c) {
    int n = (int) (c - '0');
    return n;
}

void init(int table[HEIGHT][WIDTH]) {
    memset(table, 0, sizeof(int) * HEIGHT * WIDTH);
    table[4][4] = 1;
}

void printTable(int table[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}