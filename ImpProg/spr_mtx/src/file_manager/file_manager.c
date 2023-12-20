#include "file_manager.h"

#include <stdio.h>
#include <stdlib.h>

char *generate_file_path(int n, char *dir, char *spin_dir) {
    // Here I calculate the length of the string:
    int length = snprintf(NULL, 0, "saved\\spr%d%s%s.txt", n, dir, spin_dir);

    char *file_name = (char *)malloc(length + 1);

    // Here I store the string into the file_name buffer:
    snprintf(file_name, length + 1, "saved\\spr%d%s%s.txt", n, dir, spin_dir);
    
    return file_name;
}

// |--- SAVE MATRIX TO FILE ---|
bool save_matrix(int n, int **matrix, char *file_path) {
    FILE *file_ptr = fopen(file_path, "w");

    if (file_ptr == NULL) {
        printf("Error while opening file!\n");
        return false;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(file_ptr, "%d ", matrix[i][j]);
        }
        fprintf(file_ptr, "\n");
    }

    fclose(file_ptr);
    return true;
}

// |--- LOAD MATRIX FROM FILE ---|
bool load_matrix(int ***current_matrix) {
    
}