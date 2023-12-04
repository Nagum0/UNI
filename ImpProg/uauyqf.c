#include <stdio.h>

int main(void) {
    int a, b;

    // Bekeres.
    printf("a: ");
    scanf("%d", &a);

    printf("b: ");
    scanf("%d", &b);

    int sum = a + b;

    // FILE-ba iras.
    FILE *file = fopen("ki.txt", "w");
    fprintf(file, "%d\n", sum);
    fclose(file);

    return 0;
}