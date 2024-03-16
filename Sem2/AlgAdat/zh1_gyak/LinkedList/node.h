#ifndef NODE_H
#define NODE_H

typedef struct Node {
    int key;
    struct Node *next;
} node_t;

void node_swap(node_t *a, node_t *b);

#endif