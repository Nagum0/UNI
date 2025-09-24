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
        }
        else if (p->key > max2) {
            max2 = p->key;
        }

        p = p->next;
    }

    return max2;
}

int main(void) {
    hsls_t *l = hsls_cons();

    hsls_insert_unsorted(l, 2);
    hsls_insert_unsorted(l, 10);
    hsls_insert_unsorted(l, 8);
    hsls_insert_unsorted(l, 100);
    hsls_insert_unsorted(l, -5);
    hsls_insert_unsorted(l, 29);

    hsls_display(l);

    printf("Second largest in hsls: %d\n", snd_largest(l));

    hsls_max_sort(l);
    hsls_display(l);
    
    hsls_free(l);

    return EXIT_SUCCESS;
}