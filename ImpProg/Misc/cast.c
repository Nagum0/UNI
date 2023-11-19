#include <stdio.h>

int main(void) {
    int a = 5;
    int *fptr = &a;
    int **ptr = &fptr;

    printf("%p\n%p\n%d\n", ptr, *ptr, **ptr);
    
    printf("%d\n", sizeof(int *));
    printf("%d\n", sizeof(char *));

    return 0;
}