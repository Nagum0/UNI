#include <stdio.h>
#include <stdlib.h>

void appendInt(int **array, int *arrSize, int value);

int main(void) {
    int arraySize = 0;
    int *array = NULL;

    appendInt(&array, &arraySize, 2);
    appendInt(&array, &arraySize, 3);
    appendInt(&array, &arraySize, 4);

    for (int i = 0; i < arraySize; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}

void appendInt(int **array, int *arrSize, int value) {
    int newSize = *arrSize + 1;
    int *temp = realloc(*array, newSize * sizeof(int));

    *array = temp;
    (*array)[*arrSize] = value;

    *arrSize = newSize;
}