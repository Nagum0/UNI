#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

double avg(int *a, size_t n) {
    double s = 0;

    for (size_t i = 0; i < n; i++) {
        s += a[i];
    }

    return (double) s / n;
}

void reverse(int *a, size_t n) {
    size_t i = 0;
    size_t j = n - 1;

    while (i < n - 1 && j >= 0) {
        swap(&a[i], &a[j]);
        i++;
        j--;
    }
}

void times_table(int n) {
    int i = 1;
    int j = 1;

    while (i <= n) {
        while (j <= 10) {
            printf("%d ", i * j);
            j++;
        }
        printf("\n");
        i++;
        j = 1;
    }
}

void common_nums(int *a, size_t n, int *b, size_t m) {
    int prev_printed = 0;
    
    for (size_t i = 0; i < n; i++) {
        if (a[i] != prev_printed) {
            for (size_t j = 0; j < m; j++) {
                if (a[i] == b[j]) {
                    printf("%d ", a[i]);
                    prev_printed = a[i];
                    break;
                }
            }
        }
    }
}

void sort_by_num(int *a, size_t n, int k) {
    size_t j = 0;

    for (size_t i = 0; i < n; i++) {
        if (a[i] < k) {
            swap(&a[i], &a[j]);
            j++;
        }
    }
}

void to_place(int *a, size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            swap(&a[i], &a[i + 1]);
        }
    }
}

int main() {
    int arr[] = {8, 1, 4, 11};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    int k = 7;

    /* sort_by_num(arr, n, k); */
    to_place(arr, n);

    printf("Sorted array: ");
    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}