#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Include the menu header file
#include "menu/menu.h"

#define BUFF_SIZE 100
#define INPUT_SIZE 25

// |--- USER INTERFACE ---|
int main(void) {
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
            app_run = false;
        }
        // Generate matrix:
        else if (cmd_buff == GEN_MAT) {
            // Deleting the '\n' that remains in stdin:
            getchar();

            char input[BUFF_SIZE];
            int n;
            char dir[INPUT_SIZE];
            char spin_dir[INPUT_SIZE];

            printf("Gen matrix> ");
            if (fgets(input, sizeof(input), stdin) == NULL) {
                printf("Error while reading input!\n");
                continue;
            }

            if (sscanf(input, "%d %s %s", &n, dir, spin_dir) != 3) {
                printf("Error while parsing input!\n");
                continue;
            }

            printf("%d %s %s\n", n, dir, spin_dir);
        }
        else {
            printf("Unknown command!\n");
        }
    }

    return 0;
}