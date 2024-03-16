#include <stdio.h>
#include <stdlib.h>

#include "./stack/stack.h"

void reverse_array(int *a, size_t n) {
    Stack *s = new_stack();

    for (size_t i = 0; i < n; i++) 
        push(&s, a[i]);

    for (size_t i = 0; i < n; i++)
        a[i] = pop(&s);

    delete_stack(&s);
}

int main(void) {
    int xs[] = {1, 2, 3, 4};
    size_t size = sizeof(xs) / sizeof(xs[0]);
    
    for (size_t i = 0; i < size; i++) printf("%d ", xs[i]);
    printf("\n");

    reverse_array(xs, size);

    for (size_t i = 0; i < size; i++) printf("%d ", xs[i]);
    printf("\n");

    return EXIT_SUCCESS;
}