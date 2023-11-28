#include <stdio.h>
#include "my_utils.h"

#define LEN 20

int main(void) {
    char buffer[LEN];

    if (fgets(buffer, LEN, stdin) != NULL) {
        char *str = str_cpy(buffer);
        printf("Kapott szoveg: %s\n", str);
    }
    else {
        printf("ERROR! ROSSZ INPUT!\n");
    }

    return 0;
}