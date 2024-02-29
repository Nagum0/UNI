#include <stdio.h>
#include <stdlib.h>

#include "stack\stack.h"
#include "ptf\ptf.h"

int main(void) {
    Postfix *p1 = parse_to_postfix("4 + 11 - 3");
    ptf_display(p1);
    ptf_free(p1);

    return 0;
}