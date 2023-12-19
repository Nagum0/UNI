#include "mtx.h"

#include <stdio.h>
#include <stdlib.h>

// |--- CREATE MATRIX ---|
int create_matrix(int n, char *dir, char *spin_dir, int ***current_mtx) {
    // Allocating n space for current_mtx;
    *current_mtx = (int **) malloc(n * sizeof(int *));

    if (*current_mtx == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        (*current_mtx)[i] = (int *) malloc(n * sizeof(int));

        if ((*current_mtx)[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free((*current_mtx)[j]);
            }
            free(*current_mtx);

            return 1;
        }
    }

    // Filling up the matrix with zeros (temporary):
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*current_mtx)[i][j] = 0;
        }
    }

    return 0;
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