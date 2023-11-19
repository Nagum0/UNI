#include <stdio.h>
#include <stdlib.h>

int main(void) {
    while (1 == 1) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                printf("0");
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}