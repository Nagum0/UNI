#ifndef MENU_H
#define MENU_H

typedef enum {
    GUIDE,
    GEN_MAT,
    SAVE,
    LOAD,
    PRINT,
    EXIT
} Options;

void print_menu();

#endif