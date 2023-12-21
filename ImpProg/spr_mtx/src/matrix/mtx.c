#include "mtx.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// |--- CREATE MATRIX ---|
bool check_input(int n, char *dir, char *spin_dir) {
    if ((n >= 1 && n <= 20) && 
        ((strcmp(dir, "jobbra") == 0 || strcmp(dir, "balra") == 0 || strcmp(dir, "fel") == 0) || strcmp(dir, "le") == 0 ||
          strcmp(dir, "j") == 0 || strcmp(dir, "b") == 0 || strcmp(dir, "f") == 0 || strcmp(dir, "l") == 0) &&
        ((strcmp(spin_dir, "cw") == 0 || strcmp(spin_dir, "ccw") == 0))) {
            return true;
        }
    else {
        return false;
    }
}

bool allocate_matrix(int n, int ***matrix) {
    *matrix = (int **) malloc(n * sizeof(int *));

    if (*matrix == NULL) {
        return false;
    }

    for (int i = 0; i < n; i++) {
        (*matrix)[i] = (int *) malloc(n * sizeof(int));

        if ((*matrix)[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free((*matrix)[j]);
            }
            free(*matrix);

            return false;
        }
    }

    return true;
}

// Fill the matrix with the spiral form:
void fill_matrix(int n, char *dir, char *spin, int ***matrix) {
    // Count length:
    int count = n * n;

    // Starting index position:
    int x = n - 1;
    int y = 0;
    
    int x_steps = n - 1;
    int y_steps = n - 1;
    
    while (x_steps > 0 || y_steps > 0) {
        for (int i = 0; i < x_steps; i++) {
            (*matrix)[y][x--] = count--;
        }
        for (int i = 0; i < y_steps; i++) {
            (*matrix)[y++][x] = count--;
        }
        for (int i = 0; i < x_steps; i++) {
            (*matrix)[y][x++] = count--;
        }
        for (int i = 0; i < y_steps; i++) {
            (*matrix)[y--][x] = count--;
        }

        x--;
        y++;
        x_steps -= 2;
        y_steps -= 2;
    }

    // Handle remaining element for odd dimensions:
    if (n % 2 == 1) {
        (*matrix)[y][x] = count--;
    }
}

bool create_matrix(int n, char *dir, char *spin_dir, int ***current_mtx) {
    // Check incorrect input:
    if (check_input(n, dir, spin_dir) == false) {
        printf("Incorrect input!\nCheck the guide for more information!\n");
        return false;
    }

    // Allocating memory for matrix:
    if (allocate_matrix(n, current_mtx) == false) {
        return false;
    }

    // Filling up the matrix with zeros (temporary):
    fill_matrix(n, dir, spin_dir, current_mtx);

    return true;
}

// |--- PRINT MATRIX ---|
void print_matrix(int n, int **matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// |--- FREE MATRIX ---|
void free_matrix(int n, int ***matrix) {
    for (int i = 0; i < n; i++) {
        free((*matrix)[i]);
    }
    free((*matrix));
}