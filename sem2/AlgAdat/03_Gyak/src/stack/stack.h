#ifndef STACK_H
#define STACK_h

typedef struct Stack Stack;
Stack *new_stack();
void push(Stack **stack, int data);
void peek(Stack *stack);
void display(Stack *stack);
int pop(Stack **stack);
int top(Stack *stack);
void delete_stack(Stack **stack);
int isempty(Stack *stack);

#endif