#include <stdbool.h>

#ifndef STACK_H
#define STACK_H

typedef struct Stack Stack;
Stack *create_stack(); 
void free_stack(Stack *stack);
void push_stack(Stack *stack, int x);
void display_stack(Stack *stack);
int pop_stack(Stack *stack);
int peek_stack(Stack *stack);
bool check_item(Stack *stack, int x);
void push_check_stack(Stack *stack, int x);

#endif