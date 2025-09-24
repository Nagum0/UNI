#ifndef MTX_H
#define MTX_H

#include <stdbool.h>

// |--- DIRECTIONS ---|
typedef enum {
    RIGHT,
    LEFT,
    DOWN,
    UP
} Direction;

// |--- SPIN DIRECTIONS ---|
typedef enum {
    CW,
    CCW
} Spin;

// |--- Functions for creating the matrix ---|
bool check_input(int n, char *dir, char *spin_dir);
bool allocate_matrix(int n, int ***matrix);
bool create_matrix(int n, char *dir, char *spin_dir, int ***current_mtx);

// |--- Rest of the functions ---|
void print_matrix(int n, int **matrix);
void free_matrix(int n, int ***matrix);

#endif