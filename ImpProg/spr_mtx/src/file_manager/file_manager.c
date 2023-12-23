#include "file_manager.h"
#include "..\matrix\mtx.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *generate_file_path(int n, char *dir, char *spin_dir) {
    // Here I calculate the length of the string:
    int length = snprintf(NULL, 0, "spr%d%s%s.txt", n, dir, spin_dir);

    char *file_name = (char *)malloc(length + 1);

    // Here I store the string into the file_name buffer:
    snprintf(file_name, length + 1, "spr%d%s%s.txt", n, dir, spin_dir);
    
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
bool load_matrix(int ***current_matrix, char *file_path, int *n) {
    // Reading file:
    char *buffer = NULL;

    long length;
    FILE *file_ptr = fopen(file_path, "r");

    if (file_ptr == NULL) {
        printf("Error while opening file!\n");
        return false;
    }

    fseek(file_ptr, 0, SEEK_END);
    length = ftell(file_ptr);
    fseek(file_ptr, 0, SEEK_SET);

    buffer = (char *) malloc(length + 1);

    if (buffer == NULL) {
        printf("Error while reading into buffer!\n");
        fclose(file_ptr);
        return false;
    }

    fread(buffer, 1, length, file_ptr);

    fclose(file_ptr);

    // Counting the number of rows:
    int row = 0;

    for (int i = 0; i < strlen(buffer); i++) {
        if (buffer[i] == '\n') {
            row++;
        }
    }

    // Set the n outside to row count so that when we use n with other functions the number is correct:
    *n = row;

    // Allocating memory for loaded matrix:
    if (allocate_matrix(row, current_matrix) == false) {
        printf("Error while allocating memory!\n");
        free(buffer);
        return false;
    }

    // Copying matrix:
    // (Strtok splits up the buffer by ' ' and '\n' and points to the first token after the split)
    char *token = strtok(buffer, " \n");

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            (*current_matrix)[i][j] = atoi(token);
            // (Here we continue to split the buffer)
            token = strtok(NULL, " \n");
        }
    }

    free(buffer);
    return true;
}