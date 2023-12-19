#include "menu.h"

#include <stdio.h>

void print_menu() {
    printf("--------------------------\n");
    printf("|          MENU          |\n");
    printf("--------------------------\n");
    printf("0> Guide\n");
    printf("1> Generate Matrix\n");
    printf("2> Save matrix to file\n");
    printf("3> Load matrix from file\n");
    printf("4> Print current matrix\n");
    printf("5> Exit\n");
    printf("$ ");
}