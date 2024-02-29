#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ptf.h"
#include "C:\Users\xptee\Documents\UNI\Sem2\AlgAdat\03_Gyak\src\stack\stack.h"

typedef struct Postfix {
    char *expr;
} Postfix;

enum Operator {
    PLUS,
    MINUS,
    MULT,
    DIV,
    HAT,
    OPEN_PAREN,
    CLOSING_PAREN
};

Postfix *parse_to_postfix(const char *infix_expr) {
    Postfix *new_ptf = (Postfix *) malloc(sizeof(Postfix));
    if (new_ptf == NULL) {
        fprintf(stderr, "Error while allocating memory for postfix expression.");
        free(new_ptf);
        return NULL;
    }
    
    // WRITE THE INFIX TO POSTFIX ALGORYTHM:
    new_ptf->expr = strdup(infix_expr);

    Stack *op_stack = new_stack();
    char *input = strdup(infix_expr);
    char *token = strtok(input, " ");

    while (token != NULL) {
        if (strcmp(token, "+") == 0)      push(&op_stack, PLUS);
        else if (strcmp(token, "-") == 0) push(&op_stack, MINUS);

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
    ptf = NULL;
}