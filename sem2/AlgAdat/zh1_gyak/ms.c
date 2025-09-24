#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int *a, size_t u, size_t m, size_t v) {
    size_t d = m - u;

    /* Initializing Z helper array */
    int z[d];
    for (size_t i = u; i < m; i++)
        z[i - u] = a[i];

    size_t k = u;

    size_t j = 0;
    size_t i = m;

    while (i < v && j < d) {
        if (a[i] < z[j]) {
            a[k] = a[i];
            i++;
        }
        else {
            a[k] = z[j];
            j++;
        }
        k++;
    }

    while (j < d) {
        a[k] = z[j];
        j++;
        k++;
    }
}

void ms(int *a, size_t u, size_t v) {
    if (u < v - 1) {
        size_t m = floor((double) (u + v) / 2);
        ms(a, 0, m);
        ms(a, m, v);
        merge(a, u, m, v);
    }
}

int main(void) {
    int xs[] = {5, 3, 1, 6, 8, 3, 2};
    size_t n = sizeof(xs) / sizeof(xs[0]);
    for (size_t i = 0; i < n; i++)
        printf("%d ", xs[i]);
    printf("\n");

    ms(xs, 0, n);

    for (size_t i = 0; i < n; i++)
        printf("%d ", xs[i]);
    printf("\n");

    return EXIT_SUCCESS;
}