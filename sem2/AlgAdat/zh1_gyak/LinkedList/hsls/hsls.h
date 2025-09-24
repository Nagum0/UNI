#ifndef HSLS_H
#define HSLS_H

#include "../node.h"

typedef struct Hsls {
    node_t *head;
} hsls_t;

hsls_t *hsls_cons();
void hsls_free(hsls_t *l);
void hsls_display(hsls_t *l);

int hsls_insert(hsls_t *l, int data);
int hsls_insert_unsorted(hsls_t *l, int data);
int hsls_remove(hsls_t *l, int data);

int hsls_max_sort(hsls_t *l);
void hsls_rem_even(hsls_t *l);
hsls_t *hsls_remove_odd(hsls_t *l);
void hsls_reverse(hsls_t *l);

#endif