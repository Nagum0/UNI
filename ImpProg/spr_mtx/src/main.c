#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// My includes:
#include "menu/menu.h"
#include "matrix/mtx.h"

#define BUFF_SIZE 100
#define INPUT_SIZE 25

// |--- USER INTERFACE ---|
int main(void) {
    int **current_matrix = NULL;
    int n;
    char dir[INPUT_SIZE];
    char spin_dir[INPUT_SIZE];
    bool app_run = true;

    while (app_run) {
        int cmd_buff;
        print_menu();

        // Check if the input is an integer:
        if (scanf("%d", &cmd_buff) != 1) {
            printf("Please enter a number...\n");

            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        // Exit application:
        if (cmd_buff == EXIT) {
            printf("Goodbye!\n");

            if (current_matrix != NULL) {
                free_matrix(n, &current_matrix);
            }

            app_run = false;
        }
        // Generate matrix:
        else if (cmd_buff == GEN_MAT) {
            // Deleting the '\n' that remains in stdin:
            getchar();

            char input[BUFF_SIZE];

            // Reading from stdin:
            printf("Gen matrix> ");
            if (fgets(input, sizeof(input), stdin) == NULL) {
                printf("Error while reading input!\n");
                continue;
            }

            // Parsing the input:
            if (sscanf(input, "%d %s %s", &n, dir, spin_dir) != 3) {
                printf("Error while parsing input!\n");
                continue;
            }

            // Creating matrix:
            if (create_matrix(n, dir, spin_dir, &current_matrix) == false) {
                printf("Error while creating matrix!\n");
                continue;
            }

            printf("Matrix created!\n");
        }
        // Print matrix:
        else if (cmd_buff == PRINT) {
            if (current_matrix != NULL) {
                print_matrix(n, current_matrix);
            }
            else {
                printf("No generated matrix was found!\nYou must generate a matrix first!\n");
                continue;
            }
        }
        else {
            printf("Unknown command!\n");
        }
    }

    return 0;
}