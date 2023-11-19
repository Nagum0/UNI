#include <stdio.h>
#include <string.h>

int main(void) {
    int array[3] = {1, 2, 3};

    memset(array, 0, sizeof(array));

    for (int i = 0; i < 3; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}