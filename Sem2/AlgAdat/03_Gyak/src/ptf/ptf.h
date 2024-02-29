#ifndef PTF_H
#define PTF_H

typedef struct Postfix Postfix;
Postfix *parse_to_postfix(const char *infix_expr);
void ptf_display(Postfix *ptf);
void ptf_free(Postfix *ptf);

#endif