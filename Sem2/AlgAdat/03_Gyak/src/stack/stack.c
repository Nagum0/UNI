#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

typedef struct Stack {
    int data;
    struct Stack *next;
} Stack;

Stack *new_stack() {
    Stack *top = (Stack *) malloc(sizeof(Stack));
    if (top == NULL)
        return NULL;

    top->data = 0;
    top->next = NULL;
    return top;
}

int isempty(Stack *stack) {
    return stack == NULL;
}

void push(Stack **top, int data) {
    Stack *new_node = new_stack();
    if (isempty(*top)) {
        printf("Empty stack error.\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = data;
    new_node->next = *top;
    *top = new_node;
}

void peek(Stack *top) {
    printf("%d\n", top->data);
}

void display(Stack *top) {
    Stack *current = top;
    while (current != NULL) {
        printf("%d | ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int pop(Stack **top) {
    if (isempty(*top)) {
        printf("Empty stack error.\n");
        exit(EXIT_FAILURE);
    }

    int top_data = (*top)->data;
    Stack *temp = *top;
    *top = (*top)->next;
    free(temp);
    return top_data;
}

void delete_stack(Stack **stack) {
    Stack *current = *stack;
    while (current != NULL) {
        Stack *next = current->next;
        free(current);
        current = next;
    }
    *stack = NULL;
}