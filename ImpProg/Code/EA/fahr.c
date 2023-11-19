#include <stdio.h>

int main() {
    int fahr;

    for (fahr = 100; fahr <= 400; fahr += 100) {
        printf("fahr = %d\tcelsius: %.2lf\n", fahr, ((5./9.)*(fahr - 32)));
    }

    return 0;
}