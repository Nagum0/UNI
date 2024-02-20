#include <stdio.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void push(Node *stack, int val) {
    Node node;
    node.value = val;
    node.next = NULL;
}

int main(void) {
    Node stack;
    stack.value = 69;
    stack.next = NULL;

    Node child1;
    child1.value = 15;
    child1.next = NULL;
    stack.next = &child1;

    int val = stack.next->value;
    printf("%d\n", val);
    return 0;
}