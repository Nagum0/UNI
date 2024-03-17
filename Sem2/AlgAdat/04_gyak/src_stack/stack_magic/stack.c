#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Stack {
    struct Node *top;
} Stack;

Stack *create_stack() {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    if (stack == NULL) {
        fprintf(stderr, "Error while allocating mem. for stack!\n");
        return NULL;
    }

    stack->top = NULL;
}

void free_stack(Stack *stack) {
    Node *current_node = stack->top;
    while (current_node != NULL) {
        Node *p = current_node->next;
        free(current_node);
        current_node = p;
    }
    free(stack);
}

void push_stack(Stack *stack, int x) {
    Node *node = (Node *) malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "Error while allocating mem. for node!\n");
        exit(EXIT_FAILURE);
    }

    node->data = x;
    node->next = stack->top;
    stack->top = node;
}

void display_stack(Stack *stack) {
    if (stack->top == NULL) return;

    Node *current_node = stack->top;
    while (current_node != NULL) {
        printf("%d -> ", current_node->data);
        current_node = current_node->next;
    }
    printf("NULL\n");
}

int pop_stack(Stack *stack) {
    if (stack->top == NULL) return -1;

    int data = stack->top->data;
    Node *p = stack->top;
    stack->top = stack->top->next;
    free(p);
    return data;
}

int peek_stack(Stack *stack) {
    if (stack->top == NULL) return -1;
    return stack->top->data;
}