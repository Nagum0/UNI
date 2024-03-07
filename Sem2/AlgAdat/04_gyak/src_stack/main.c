#include <stdio.h>
#include <stdlib.h>
#include "stack\stack.h"

int main(void) {
    Stack *stack = create_stack();
    if (stack == NULL) goto err;

    push_stack(stack, 69);
    push_stack(stack, 420);
    display_stack(stack);
    free_stack(stack);

    return EXIT_SUCCESS;

err:
    fprintf(stderr, "You messed up buddy!\n");
    return EXIT_FAILURE;
}