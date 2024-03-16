#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

size_t partition(int *a, size_t p, size_t r) {
    size_t i = ceil((p + r - 1) / 2);
    swap(&a[r], &a[i]);
    i = p;

    while (i < r && a[r] >= a[i]) {
        i++;
    }

    if (i < r) {
        size_t j = i + 1;
        while (j < r) {
            if (a[j] < a[r]) {
                swap(&a[j], &a[i]);
                i++;
            }
            j++;
        }
        swap(&a[i], &a[r]);
    }

    return i;
}

void quicksort(int *a, size_t p, size_t r) {
    if (p < r) {
        size_t q = partition(a, p, r);
        quicksort(a, p, q - 1);
        quicksort(a, q + 1, r);
    }
    else {
        return;
    }
}

void max_kiv_rend(int *a, size_t n) {
    for (size_t i = n - 1; i > 0; i--) {
        for (size_t j = 0; j < i; j++) {
            if (a[j] > a[i]) {
                swap(&a[j], &a[i]);
            }
        }
    }
}

void naive_ins_sort(int *a, size_t n) {
    for (size_t i = 1; i < n; i++) {
        size_t j = i;
        while (j > 0 && a[j - 1] > a[j]) {
            swap(&a[j - 1], &a[j]);
            j--;
        }
    }
}

int main(void) {
    size_t r = 6;
    int arr[6] = {10, 2, 5, 1, 3, 9};
    
    for (int i = 0; i < r; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
    //quicksort(arr, 0, r - 1);
    //max_kiv_rend(arr, r);
    naive_ins_sort(arr, r);

    for (int i = 0; i < r; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
