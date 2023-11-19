#include <stdio.h>
#include <string.h>

void name_card(int length, char *name, int margin) {
    int line_length = length + margin;

    // Printing top layer
    for (int i = 0; i <= line_length; i++) {
        printf("x ");
    }
    printf("\n");

    // Printing empty line
    for (int i = 0; i <= line_length; i++) {
        if (i == 0) {
            printf("x");
        }
        else if (i == line_length) {
            printf(" x\n");
        }
        else {
            printf("  ");
        }
    }

    // Printing name
    for (int i = 0; i <= line_length; i++) {
        if (i == 0) {
            printf("x");
        }
        else if (i == line_length) {
            printf(" x\n");
        }
        else if (i > length) {
            printf("  ");
        }
        else {
            printf("%c", name[i-1]);
        }
    }
}

int main(void) {
    char name[] = "Astolfo";
    name_card(strlen(name), name, 4);

    return 0;
}
