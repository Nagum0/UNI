#include "mtx.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// |--- CREATE MATRIX ---|
// Check input for matrix:
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

// Allocate memory for a matrix:
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
void fill_matrix(int n, Direction dir, Spin spin, int ***matrix) {
    // Pointer to matrix:
    int **mtx_ptr = (*matrix);
    
    // Number counter:
    int count = n * n;

    // Determining the starting coordinates and filling up the matrix:
    int x_steps = n - 1;
    int y_steps = n - 1;
    int x, y = 0;
    
    // Calculate the starting coords:
    if ((dir == UP && spin == CW && n % 2 == 0) || (dir == RIGHT && spin == CCW && n % 2 != 0) ||
        (dir == LEFT && spin == CCW && n % 2 == 0) || (dir == DOWN && spin == CW && n % 2 != 0)) {
        x = n - 1;
        y = n - 1;
    }
    else if ((dir == UP && spin == CCW && n % 2 == 0) || (dir == RIGHT && spin == CW && n % 2 == 0) ||
             (dir == LEFT && spin == CW && n % 2 != 0) || (dir == DOWN && spin == CCW && n % 2 != 0)) {
        x = 0;
        y = n - 1;
    }
    else if ((dir == UP && spin == CW && n % 2 != 0) || (dir == RIGHT && spin == CCW && n % 2 == 0) ||
             (dir == LEFT && spin == CCW && n % 2 != 0) || (dir == DOWN && spin == CW && n % 2 == 0)) {
        x = 0;
        y = 0;
    }
    else {
        x = n - 1;
        y = 0;
    }

    // Filling the matrix:
    while (x_steps > 0 || y_steps > 0) {
        // UP/DOWN
        if (dir == UP || dir == DOWN) {
            for (int i = 0; i < y_steps; i++) {
                // UP
                if (dir == UP && spin == CW && n % 2 == 0) mtx_ptr[y--][x] = count--;
                else if (dir == UP && spin == CW && n % 2 != 0) mtx_ptr[y++][x] = count--;
                else if (dir == UP && spin == CCW && n % 2 == 0) mtx_ptr[y--][x] = count--;
                else if (dir == UP && spin == CCW && n % 2 != 0) mtx_ptr[y++][x] = count--;
                // DOWN
                else if (dir == DOWN && spin == CW && n % 2 == 0) mtx_ptr[y++][x] = count--;
                else if (dir == DOWN && spin == CW && n % 2 != 0) mtx_ptr[y--][x] = count--;
                else if (dir == DOWN && spin == CCW && n % 2 == 0) mtx_ptr[y++][x] = count--;
                else if (dir == DOWN && spin == CCW && n % 2 != 0) mtx_ptr[y--][x] = count--;
            }
            for (int i = 0; i < x_steps; i++) {
                // UP
                if (dir == UP && spin == CW && n % 2 == 0) mtx_ptr[y][x--] = count--;
                else if (dir == UP && spin == CW && n % 2 != 0) mtx_ptr[y][x++] = count--;
                else if (dir == UP && spin == CCW && n % 2 == 0) mtx_ptr[y][x++] = count--;
                else if (dir == UP && spin == CCW && n % 2 != 0) mtx_ptr[y][x--] = count--;
                // DOWN
                else if (dir == DOWN && spin == CW && n % 2 == 0) mtx_ptr[y][x++] = count--;
                else if (dir == DOWN && spin == CW && n % 2 != 0) mtx_ptr[y][x--] = count--;
                else if (dir == DOWN && spin == CCW && n % 2 == 0) mtx_ptr[y][x--] = count--;
                else if (dir == DOWN && spin == CCW && n % 2 != 0) mtx_ptr[y][x++] = count--;
            }
            for (int i = 0; i < y_steps; i++) {
                // UP
                if (dir == UP && spin == CW && n % 2 == 0) mtx_ptr[y++][x] = count--;
                else if (dir == UP && spin == CW && n % 2 != 0) mtx_ptr[y--][x] = count--;
                else if (dir == UP && spin == CCW && n % 2 == 0) mtx_ptr[y++][x] = count--;
                else if (dir == UP && spin == CCW && n % 2 != 0) mtx_ptr[y--][x] = count--;
                // DOWN
                else if (dir == DOWN && spin == CW && n % 2 == 0) mtx_ptr[y--][x] = count--;
                else if (dir == DOWN && spin == CW && n % 2 != 0) mtx_ptr[y++][x] = count--;
                else if (dir == DOWN && spin == CCW && n % 2 == 0) mtx_ptr[y--][x] = count--;
                else if (dir == DOWN && spin == CCW && n % 2 != 0) mtx_ptr[y++][x] = count--;
            }
            for (int i = 0; i < x_steps; i++) {
                // UP
                if (dir == UP && spin == CW && n % 2 == 0) mtx_ptr[y][x++] = count--;
                else if (dir == UP && spin == CW && n % 2 != 0) mtx_ptr[y][x--] = count--;
                else if (dir == UP && spin == CCW && n % 2 == 0) mtx_ptr[y][x--] = count--;
                else if (dir == UP && spin == CCW && n % 2 != 0) mtx_ptr[y][x++] = count--;
                // DOWN
                else if (dir == DOWN && spin == CW && n % 2 == 0) mtx_ptr[y][x--] = count--;
                else if (dir == DOWN && spin == CW && n % 2 != 0) mtx_ptr[y][x++] = count--;
                else if (dir == DOWN && spin == CCW && n % 2 == 0) mtx_ptr[y][x++] = count--;
                else if (dir == DOWN && spin == CCW && n % 2 != 0) mtx_ptr[y][x--] = count--;
            }
        }
        // RIGHT/LEFT
        else if (dir == RIGHT || dir == LEFT) {
            for (int i = 0; i < x_steps; i++) {
                // RIGHT
                if (dir == RIGHT && spin == CW && n % 2 == 0) mtx_ptr[y][x++] = count--;
                else if (dir == RIGHT && spin == CW && n % 2 != 0) mtx_ptr[y][x--] = count--;
                else if (dir == RIGHT && spin == CCW && n % 2 == 0) mtx_ptr[y][x++] = count--;
                else if (dir == RIGHT && spin == CCW && n % 2 != 0) mtx_ptr[y][x--] = count--;
                // LEFT
                if (dir == LEFT && spin == CW && n % 2 == 0) mtx_ptr[y][x--] = count--;
                else if (dir == LEFT && spin == CW && n % 2 != 0) mtx_ptr[y][x++] = count--;
                else if (dir == LEFT && spin == CCW && n % 2 == 0) mtx_ptr[y][x--] = count--;
                else if (dir == LEFT && spin == CCW && n % 2 != 0) mtx_ptr[y][x++] = count--;
            }
            for (int i = 0; i < y_steps; i++) {
                // RIGHT
                if (dir == RIGHT && spin == CW && n % 2 == 0) mtx_ptr[y--][x] = count--;
                else if (dir == RIGHT && spin == CW && n % 2 != 0) mtx_ptr[y++][x] = count--;
                else if (dir == RIGHT && spin == CCW && n % 2 == 0) mtx_ptr[y++][x] = count--;
                else if (dir == RIGHT && spin == CCW && n % 2 != 0) mtx_ptr[y--][x] = count--;
                // LEFT
                if (dir == LEFT && spin == CW && n % 2 == 0) mtx_ptr[y++][x] = count--;
                else if (dir == LEFT && spin == CW && n % 2 != 0) mtx_ptr[y--][x] = count--;
                else if (dir == LEFT && spin == CCW && n % 2 == 0) mtx_ptr[y--][x] = count--;
                else if (dir == LEFT && spin == CCW && n % 2 != 0) mtx_ptr[y++][x] = count--;
            }
            for (int i = 0; i < x_steps; i++) {
                // RIGHT
                if (dir == RIGHT && spin == CW && n % 2 == 0) mtx_ptr[y][x--] = count--;
                else if (dir == RIGHT && spin == CW && n % 2 != 0) mtx_ptr[y][x++] = count--;
                else if (dir == RIGHT && spin == CCW && n % 2 == 0) mtx_ptr[y][x--] = count--;
                else if (dir == RIGHT && spin == CCW && n % 2 != 0) mtx_ptr[y][x++] = count--;
                // LEFT
                if (dir == LEFT && spin == CW && n % 2 == 0) mtx_ptr[y][x++] = count--;
                else if (dir == LEFT && spin == CW && n % 2 != 0) mtx_ptr[y][x--] = count--;
                else if (dir == LEFT && spin == CCW && n % 2 == 0) mtx_ptr[y][x++] = count--;
                else if (dir == LEFT && spin == CCW && n % 2 != 0) mtx_ptr[y][x--] = count--;
            }
            for (int i = 0; i < y_steps; i++) {
                // RIGHT
                if (dir == RIGHT && spin == CW && n % 2 == 0) mtx_ptr[y++][x] = count--;
                else if (dir == RIGHT && spin == CW && n % 2 != 0) mtx_ptr[y--][x] = count--;
                else if (dir == RIGHT && spin == CCW && n % 2 == 0) mtx_ptr[y--][x] = count--;
                else if (dir == RIGHT && spin == CCW && n % 2 != 0) mtx_ptr[y++][x] = count--;
                // LEFT
                if (dir == LEFT && spin == CW && n % 2 == 0) mtx_ptr[y--][x] = count--;
                else if (dir == LEFT && spin == CW && n % 2 != 0) mtx_ptr[y++][x] = count--;
                else if (dir == LEFT && spin == CCW && n % 2 == 0) mtx_ptr[y++][x] = count--;
                else if (dir == LEFT && spin == CCW && n % 2 != 0) mtx_ptr[y--][x] = count--;
            }
        }

        // Calculating where to indent the coordinate pointers:
        if (dir == UP && spin == CW && n % 2 == 0) { x--; y--; }
        else if (dir == UP && spin == CW && n % 2 != 0) { x++; y++; }
        else if (dir == UP && spin == CCW && n % 2 == 0) { x++; y--; }
        else if (dir == UP && spin == CCW && n % 2 != 0) { x--; y++; }
        else if (dir == DOWN && spin == CW && n % 2 == 0) { x++; y++; }
        else if (dir == DOWN && spin == CW && n % 2 != 0) { x--; y--; }
        else if (dir == DOWN && spin == CCW && n % 2 == 0) { x--; y++; }
        else if (dir == DOWN && spin == CCW && n % 2 != 0) { x++; y--; }
        else if (dir == RIGHT && spin == CW && n % 2 == 0) { x++; y--; }
        else if (dir == RIGHT && spin == CW && n % 2 != 0) { x--; y++; }
        else if (dir == RIGHT && spin == CCW && n % 2 == 0) { x++; y++; }
        else if (dir == RIGHT && spin == CCW && n % 2 != 0) { x--; y--; }
        else if (dir == LEFT && spin == CW && n % 2 == 0) { x--; y++; }
        else if (dir == LEFT && spin == CW && n % 2 != 0) { x++; y--; }
        else if (dir == LEFT && spin == CCW && n % 2 == 0) { x--; y--; }
        else if (dir == LEFT && spin == CCW && n % 2 != 0) { x++; y++; }

        x_steps -= 2;
        y_steps -= 2;
    }

    // Place final element in the center if n is odd:
    if (n % 2 != 0) {
        mtx_ptr[y][x] = 1;
    }
}

// Get direction:
Direction get_direction(char *dir) {
    if (strcmp(dir, "jobbra") == 0 || strcmp(dir, "j") == 0) {
        return RIGHT;
    }
    else if (strcmp(dir, "balra") == 0, strcmp(dir, "b") == 0) {
        return LEFT;
    }
    else if (strcmp(dir, "fel") == 0 || strcmp(dir, "f") == 0) {
        return UP;
    }
    else if (strcmp(dir, "le") == 0 || strcmp(dir, "l") == 0) {
        return DOWN;
    }
}

// Get spin:
Spin get_spin(char *spin) {
    if (strcmp(spin, "cw") == 0) {
        return CW;
    }
    else if (strcmp(spin, "ccw") == 0) {
        return CCW;
    }
}

bool create_matrix(int n, char *dir, char *spin_dir, int ***current_mtx) {
    // Allocating memory for matrix:
    if (allocate_matrix(n, current_mtx) == false) {
        return false;
    }

    // Filling up the matrix in a spiral form:
    fill_matrix(n, get_direction(dir), get_spin(spin_dir), current_mtx);

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