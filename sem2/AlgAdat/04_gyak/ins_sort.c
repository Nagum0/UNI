#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void naive_insertion_sort(int a[], size_t n) {
    for (size_t i = 1; i < n; i++) {
        size_t j = i;
        while (j > 0 && a[j - 1] > a[j]) {
            swap(&a[j - 1], &a[j]);
            j--;
        }
    }
}

int main(void) {
    int arr[] = {7, 3, 4 ,1};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    naive_insertion_sort(arr, size);
    printf("\n");
    
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return EXIT_SUCCESS;
}