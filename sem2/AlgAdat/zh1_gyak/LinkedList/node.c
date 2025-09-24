#include "node.h"

#include <stdio.h>
#include <stdlib.h>

void node_swap(node_t *a, node_t *b) {
    int temp = a->key;
    a->key = b->key;
    b->key = temp;
}