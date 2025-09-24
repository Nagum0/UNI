#ifndef MENU_H
#define MENU_H

typedef enum {
    MAN,
    GEN_MAT,
    SAVE,
    LOAD,
    PRINT,
    EXIT
} Options;

void print_menu();
void print_guide();

#endif