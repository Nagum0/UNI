#ifndef MTX_H
#define MTX_H

#include <stdbool.h>

bool create_matrix(int n, char *dir, char *spin_dir, int ***current_mtx);
bool allocate_matrix(int n, int ***matrix);
void print_matrix(int n, int **matrix);
void free_matrix(int n, int ***matrix);

#endif