#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "./stack_magic/stack.h"
/* #include "./src_que/queue/que.h" */

#include "./LinkedList/node.h"
#include "./LinkedList/hsls/hsls.h"


int get_longest_sorted(int a[], size_t n) {
    int max = 0;
    int c = 1;
    int k = a[0];

    for (size_t i = 1; i < n; i++) {
        if (k < a[i]) {
            c++;
            k = a[i];
        }
        else {
            if (max < c) {
                max = c;
                c = 0;
            }
            else {
                c = 0;
            }
        }
    }

    return max;
}

int snd_largest(hsls_t *l) {
    node_t *p = l->head->next; 
    int max1 = p->key;
    int max2 = p->key;

    while (p != NULL) {
        if (p->key > max1) {
            max2 = max1;    
            max1 = p->key;
        }

        p = p->next;
    }

    return max2;
}

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

    int a[] = {1,2,3,9,1,7,8,11,2,3,4,5};
    size_t n = sizeof(a) / sizeof(a[0]);
    printf("Longest sorted sequence: %d\n", get_longest_sorted(a, n));

    hsls_t *hl = hsls_cons();

    hsls_insert(hl, 4);
    hsls_insert(hl, 5);
    hsls_insert(hl, 1);
    hsls_insert(hl, 10);
    hsls_display(hl);

    printf("Second largest int in hl: %d\n", snd_largest(hl));

    hsls_free(hl);

    return EXIT_SUCCESS;
}
