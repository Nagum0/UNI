#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include ".\m_str\m_str.h"

/* PRINT STRING LENGTH MACRO */
#define PRINT_STR_LEN(str) \
    print_string(str); \
    printf("strlen: %d\n", len_string(str)); \
    printf("\n");

int main(void) {
    printf("-->> TEST BUILD <<--\n");

    /* Constructing */
    String *str1 = new_string("Test");
    PRINT_STR_LEN(str1);

    /* Pushing char */
    push_char_string(str1, 'x');
    PRINT_STR_LEN(str1);

    /* Pushing string literals */
    push_const_string(str1, " LMAO");
    PRINT_STR_LEN(str1);

    /* Pushing string to string */
    String *str2 = new_string(" yeesh");
    PRINT_STR_LEN(str2);
    String *cons_str = push_string(str1, str2);
    PRINT_STR_LEN(cons_str);
    free_string(cons_str);    

    free_string(str1);

    return EXIT_SUCCESS;
}