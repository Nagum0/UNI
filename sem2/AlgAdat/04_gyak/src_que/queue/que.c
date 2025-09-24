#include "que.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    struct Node *first;
    struct Node *last;
    int size;
} Queue;

Queue *create_queue() {
    /* Creating the queue */
    Queue *que = (Queue *) malloc(sizeof(Queue));
    if (que == NULL) {
        fprintf(stderr, "Error while allocating memory for the queue!\n");
        exit(EXIT_FAILURE);
    }

    /* Creating the node */
    Node *node = (Node *) malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "Error while allocating memory for the node!\n");
        exit(EXIT_FAILURE);
    }

    que->last = node;
    que->first = que->last;
    que->first->next = NULL;
    que->size = 0;
}

void free_queue(Queue *que) {
    Node *current_node = que->first;
    while (current_node != NULL) {
        Node *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    free(que);
}

void queue_add(Queue *que, int x) {
    /* Creating the new node */
    Node *node = (Node *) malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "Error while allocating memory for the node!\n");
        exit(EXIT_FAILURE);
    }

    que->last->next = node;
    que->last->data = x;
    que->last = que->last->next;
    que->last->next = NULL;
    que->size++;
}

int queue_remove(Queue *que) {
    if (que->size == 0) {
        fprintf(stderr, "Empty queue!\n");
        exit(EXIT_FAILURE);
    }

    Node *first_ptr = que->first;
    int first_data = que->first->data;
    que->first = que->first->next;
    que->size--;
    free(first_ptr);
    return first_data;
}

void queue_display(Queue *que) {
    if (que->size == 0)
        return;

    Node *current_node = que->first;
    size_t size = que->size;
    while (size != 1) {
        printf("%d -> ", current_node->data);
        current_node = current_node->next;
        size--;
    }
    printf("%d -> NULL\n", current_node->data);
}

int queue_first(Queue *que) {
    if (que->size == 0)
        return -1;
    return que->first->data;
}

int queue_len(Queue *que) {
    return que->size;
}

int queue_is_empty(Queue *que) {
    if (que->size == 0)
        return 0;
    return 1;
}

void queue_set_empty(Queue *que) {
    if (queue_is_empty(que) == 0) {
        return;
    }

    while (que->first != que->last) {
        Node *p = que->first;
        que->first = que->first->next;
        free(p);
    }

    que->size = 0;
}
