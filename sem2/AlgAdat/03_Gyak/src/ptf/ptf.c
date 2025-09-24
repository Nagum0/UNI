#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ptf.h"
#include "C:\Users\xptee\Documents\UNI\Sem2\AlgAdat\03_Gyak\src\stack\stack.h"

/* --- PRIVATE --- */
typedef enum Operator {
    PLUS,
    MINUS,
    MULT,
    DIV,
    HAT,
    OPEN_PAREN,
    CLOSING_PAREN
} Operator;

char parse_op(Operator op) {
    switch (op)
    {
    case PLUS:
        return '+';
    case MINUS:
        return '-';
    case MULT:
        return '*';
    case DIV:
        return '/';
    case HAT:
        return '^';
    default:
        return 'a';
    }
}

int is_number(char *str) {
    for (int i = 0; i < strlen(str); i++)
        if (isdigit(str[i]) == 0)
            return 1;

    return 0; 
}

/* --- PUBLIC --- */

typedef struct Postfix {
    char *expr;
} Postfix;

Postfix *parse_to_postfix(const char *infix_expr) {
    Postfix *new_ptf = (Postfix *) malloc(sizeof(Postfix));
    if (new_ptf == NULL) {
        fprintf(stderr, "Error while allocating memory for postfix expression.");
        free(new_ptf);
        return NULL;
    }

    new_ptf->expr = (char *) malloc(sizeof(char) * (strlen(infix_expr) + 1));
    if (new_ptf->expr == NULL) {
        fprintf(stderr, "Error while allocating memory for postfix expression.");
        free(new_ptf->expr);
        free(new_ptf);
        return NULL;
    }

    // WRITE THE INFIX TO POSTFIX ALGORYTHM:
    Stack *op_stack = new_stack();
    char *input = strdup(infix_expr);
    char *token = strtok(input, " ");
    
    while (token != NULL) {
        if (strcmp(token, "(") == 0)
            push(&op_stack, OPEN_PAREN);
        else if (strcmp(token, ")") == 0) {
            while (top(op_stack) != OPEN_PAREN) {
                strcat(new_ptf->expr, parse_op(pop(&op_stack)));
            }
            pop(&op_stack);
        }
        token = strtok(NULL, " ");
    }

    display(op_stack);
    delete_stack(&op_stack);
    return new_ptf;
}

void ptf_display(Postfix *ptf) {
    printf("%s\n", ptf->expr);
}

void ptf_free(Postfix *ptf) {
    free(ptf->expr);
    free(ptf);
}