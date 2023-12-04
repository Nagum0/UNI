#include <stdio.h>
#include "utils.h"

int main(void) {
    date_t birthDate = createDate(2004, 6, 4);
    destroyDate(birthDate);
    
    date_t testDate = createDate(1984, 13, 42);
    destroyDate(testDate);

    return 0;
}