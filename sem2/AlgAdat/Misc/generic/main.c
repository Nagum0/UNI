#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LEN 64

typedef struct Bar {
    char name[MAX_LEN];
    int age;
    void *x;
} bar_t;

typedef enum Type {
    CHAR,
    INT,
} Type;

void swap(void *a, void *b, Type t) {
    
}

int main(void) {
    bar_t bar = {
        .name = "Zeki",
        .age = 19,
        .x = (char *) 'a'
    };

    char a = 'a';
    char b = 'b';
    swap(&a, &b, CHAR);

    char name[MAX_LEN];
    fgets(name, MAX_LEN, stdin);
    printf("name: %s", name);

    return EXIT_SUCCESS;
}