#include <stdio.h>

double fahr2cels(double fahr) {
    return 5./9. * (fahr - 32);
}

int main() {
    int fahr;

    for (fahr = 100; fahr <= 400; fahr += 100) {
        printf("fahr = %4d\tcelsius = %.2lf\n", fahr, fahr2cels(fahr));
    }

    return 0;
}