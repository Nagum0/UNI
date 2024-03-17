#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "./stack_magic/stack.h"
/* #include "./src_que/queue/que.h" */

int main(void) {
    Stack *v = create_stack();

    push_stack(v, 6);
    push_stack(v, 7);
    push_stack(v, 8);
    push_stack(v, 4);
    push_stack(v, 1);

    display_stack(v);
    bool l = check_item(v, 7);
    printf("%s\n", l ? "true" : "false");

    push_check_stack(v, 7);
    display_stack(v);

    free_stack(v);

    return EXIT_SUCCESS;
}
