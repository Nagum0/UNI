#include <stdio.h>
#include <stdlib.h>

int append_int(int value, int *array, int array_size);

int main(void) {
    int *p = (int *) malloc(sizeof(int) * 2);
    p[0] = 1;
    p[1] = 2;

    append_int(8, p, 2);

    return 0;
}

int append_int(int value, int *array, int array_size) {
    for (int i = 0; i < array_size; i++) {
        printf("%d\n", array[i]);
    }
}