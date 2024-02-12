#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "my_utils.h"

#define LEN 20

char *str_cpy(char *str) {
    int len = strlen(str);
    
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    char *cp_str = malloc(strlen(str) + 1);

    if (cp_str == NULL) {
        printf("Nem sikerult a memoria fogalalas!\n");
        return cp_str;
    }

    

    return cp_str;
}