#include "m_str.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct String {
    char *content;
} String;

String *new_string(const char *input) {
    String *str = (String *) malloc(sizeof(String));
    if (str == NULL) goto err;

    str->content = (char *) malloc(sizeof(char) * strlen(input) + 1);
    if (str->content == NULL) goto err;

    strcpy(str->content, input);

    return str;

err:
    fprintf(stderr, "Error while creating string!\n");
    return NULL;
}

void free_string(String *str) {
    free(str->content);
    free(str);
}

void free_arr_string(String **arr, size_t size) {
    for (int i = 0; i < size; i++) {
        free(arr[i]->content);
        free(arr[i]);
    }
}

void push_const_string(String *str, const char *input) {
    size_t new_str_len = strlen(str->content) + strlen(input) + 1;
    size_t old_len = strlen(str->content);

    str->content= (char *) realloc(str->content, sizeof(char) * new_str_len);
    if (str->content == NULL) {
        fprintf(stderr, "Error while concatting string!\n");
        exit(EXIT_FAILURE);
    }
    
    for (size_t i = old_len; i < new_str_len - 1; i++) {
        str->content[i] = input[i - old_len];
    }
    str->content[new_str_len - 1] = '\0';
}

String *push_string(String *str1, String *str2) {
    String *new_str = (String *) malloc(sizeof(String));
    if (new_str == NULL) {
        fprintf(stderr, "Error while creating string!\n");
        return NULL;
    }

    size_t new_str_len = strlen(str1->content) + strlen(str2->content) + 1;
    new_str->content = (char *) malloc(sizeof(char) * new_str_len);
    if (new_str->content == NULL) {
        fprintf(stderr, "Error while creating string!\n");
        return NULL;
    }

    strcpy(new_str->content, str1->content);
    strcat(new_str->content, str2->content);

    return new_str;
}

void push_char_string(String *str, const char c) {
    str->content = (char *) realloc(str->content, sizeof(char) * strlen(str->content) + 2);
    if (str->content == NULL) {
        fprintf(stderr, "Error while pushing character to string!\n");
        exit(EXIT_FAILURE);
    }

    size_t new_size = strlen(str->content);
    str->content[new_size] = c;
    str->content[new_size + 1] = '\0';
}

void print_string(String *str) {
    printf("%s\n", str->content);
}

size_t len_string(String *str) {
    return strlen(str->content);
}