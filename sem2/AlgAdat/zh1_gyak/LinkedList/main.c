#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "sls/sls.h"
#include "hsls/hsls.h"

int snd_largest(hsls_t *l) {
    node_t *p = l->head->next; 
    int max1 = p->key;
    int max2 = p->key;

    while (p != NULL) {
        if (p->key > max1) {
            max1 = p->key;
            max2 = max1;
        }

        /* if (p->key > max1) {
            max1 = p->key;
        }
        else if (p->key > max2) {
            max2 = p->key;
        } */

        p = p->next;
    }

    return max2;
}

int main(void) {
    node_t *l = NULL;
    sls_insert(&l, 1);
    sls_insert(&l, 2);
    sls_insert(&l, 3);
    sls_insert(&l, 4);
    sls_display(l);

    sls_reverse(&l);
    sls_display(l);

    sls_free(&l);

    /* hsls_t *l = hsls_cons();

    hsls_insert_unsorted(l, 2);
    hsls_insert_unsorted(l, 10);
    hsls_insert_unsorted(l, 8);
    hsls_insert_unsorted(l, 100);
    hsls_insert_unsorted(l, -5);
    hsls_insert_unsorted(l, 29);

    hsls_display(l);
    hsls_rem_even(l);
    hsls_display(l);
    
    hsls_t *odds = hsls_remove_odd(l);
    hsls_display(l);
    hsls_display(odds);

    hsls_reverse(l);
    hsls_display(l);

    hsls_free(odds);
    hsls_free(l); */

    return EXIT_SUCCESS;
}