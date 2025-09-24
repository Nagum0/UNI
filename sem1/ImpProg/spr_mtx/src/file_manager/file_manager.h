#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <stdbool.h>

char *generate_file_path(int n, char *dir, char *spin_dir);
bool save_matrix(int n, int **matrix, char *file_path);
bool load_matrix(int ***current_matrix, char *file_path, int *n);

#endif