#include <stdio.h>

int main(void) {
    float z = 3.4;
    int y = (int) z;
    printf("y = %d\n", y);

    int array[5] = {0,0,0,0,0};
    int arraySize = sizeof(array) / sizeof(int);

    printf("arraySize = %d\n", arraySize);

    int nullSizeArray[0];
    nullSizeArray[0] = 2;
    nullSizeArray[1] = 3;
    nullSizeArray[2] = 4;

    printf("nullSizeArray[0] = %d\n", nullSizeArray[0]);
    printf("nullSizeArray[1] = %d\n", nullSizeArray[1]);
    printf("nullSizeArray[2] = %d\n", nullSizeArray[2]);

    for (int i = 0; i < 3; i++) {
        printf("%p ", &nullSizeArray[i]);
    }
    printf("\n%p\n", *(nullSizeArray + 1));

    char var[3];
    var[0] = 'v';
    var[1] = 'a';
    var[2] = 'r';

    for (int i = 0; i < 3; i++) {
        printf("%p ", &var[i]);
    }
    printf("\n");

    return 0;
}