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

bool create_matrix(int n, char *dir, char *spin_dir, int ***current_mtx) {
    // Check incorrect input:
    if (check_input(n, dir, spin_dir) == false) {
        printf("Incorrect input!\nCheck the guide for more information!\n");
        return false;
    }

    // Allocating n space for current_mtx;
    *current_mtx = (int **) malloc(n * sizeof(int *));

    if (*current_mtx == NULL) {
        return false;
    }

    for (int i = 0; i < n; i++) {
        (*current_mtx)[i] = (int *) malloc(n * sizeof(int));

        if ((*current_mtx)[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free((*current_mtx)[j]);
            }
            free(*current_mtx);

            return false;
        }
    }

    // Filling up the matrix with zeros (temporary):
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*current_mtx)[i][j] = 0;
        }
    }

    return true;
}

// |--- PRINT MATRIX ---|
void print_matrix(int n, int **matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
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