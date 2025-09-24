#include <stdio.h>

int main(void) {
    for (char c = 'a'; c != 'z'; c++) {
        printf("%c\n", c);
    }
    printf("z\n");

    return 0;
}