#include <stdlib.h>

#ifndef M_STR_H
#define M_STR_H

typedef struct String String;

/* Constructor and destructor */
String *new_string(const char *input);
void free_string(String *str);
void free_arr_string(String **arr, size_t size);

/* String concatting and character pushing */
void push_const_string(String *str, const char *input);
String *push_string(String *str, String *str2);
void push_char_string(String *str, const char c);

/* Split */

/* Print */
void print_string(String *str);

/* Getters */
size_t len_string(String *str);

#endif