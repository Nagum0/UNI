#ifndef MTX_H
#define MTX_H

int create_matrix(int n, char *dir, char *spin_dir, int ***current_mtx);
void print_matrix(int n, int **matrix);
void free_matrix(int n, int ***matrix);

#endif