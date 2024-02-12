#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 10
#define WIDTH 10

#define BUFFERS_SIZE 100

extern void init(int table[HEIGHT][WIDTH]);
extern void printTable(int table[HEIGHT][WIDTH]);
extern void fillTable(int table[HEIGHT][WIDTH]);
extern void inputData(int table[HEIGHT][WIDTH]);

int main(void) {
    int table[HEIGHT][WIDTH];
    init(table);

    inputData(table);
    printTable(table);

    return 0;
}

void inputData(int table[HEIGHT][WIDTH]) {
    char buffer[BUFFERS_SIZE];

    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        int value = atoi(buffer);

        if (value == 0 && buffer[0] != '0') {
            printf("Incorrect input!\n");
        }
        else {
            
        }
    }
}

void init(int table[HEIGHT][WIDTH]) {
    memset(table, 0, sizeof(int) * HEIGHT * WIDTH);
}

void printTable(int table[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}

void fillTable(int table[HEIGHT][WIDTH]) {
    srand(time(NULL));

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            table[i][j] = rand() % 100 + 1;
        }
    }
}