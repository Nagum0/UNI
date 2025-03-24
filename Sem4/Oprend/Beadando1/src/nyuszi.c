#include "../headers/nyuszi.h"
#include <stdio.h>

void nyuszi_print(nyuszi_t nyuszi) {
    printf("----------------- %s -----------------\n", nyuszi.name);
    printf("Tojasok: %d\n", nyuszi.eggs);
    printf("%s\n", nyuszi.vers);
}
