#include "menu.h"

#include <stdio.h>

void print_menu() {
    printf("|-------------------------------------------|\n");
    printf("|          Spiral Matrix Generator          |\n");
    printf("|-------------------------------------------|\n");
    printf("0> Manual\n");
    printf("1> Generate Matrix\n");
    printf("2> Save matrix to file\n");
    printf("3> Load matrix from file\n");
    printf("4> Print current matrix\n");
    printf("5> Exit\n");
    printf("$ ");
}

void print_guide() {
    printf("Welcome to the Spiral Matrix Generator manual!\n");
    printf("Option 1: (Generate Matrix)\n");
    printf("\tAfter entering 1 the app will prompt you with `Matrix parameters>`.\n");
    printf("\tHere you need to enter 3 values separated by spaces.\n");
    printf("\tFirst parameter: the dimension of the matrix (1..20) (the matrix is always NxN so only one number is needed).\n");
    printf("\tSecond parameter: the direction of the spiral. These are the possible directions:\n");
    printf("\tb/balra, j/jobbra, f/fel, l/le.\n");
    printf("\tThird parameter: the spinning direction: cw (clockwise), ccw (counterclockwise).\n");
    printf("Option 2: (Save matrix to file)\n");
    printf("\tAfter a matrix was either generated or loaded it can be saved to a file.\n");
    printf("\t(The name of the file will be in the format of the parameters given\n\ta it will be saved in the directory from which the app is running from)\n");
    printf("Option 3: (Load matrix from file)\n");
    printf("\tYou will be prompted with `Matrix name to be loaded`. You need to enter the name of the matrix you want to load.\n");
    printf("\t(After loading the currently generated matrix (if there is one) will be overwritten by the loaded one.)\n");
    printf("Option 4: (Print current matrix)\n");
    printf("\tPrints the current matrix to the terminal.\n");
    printf("Option 5: (Exit)\n");
    printf("\tExit the application.\n");
}