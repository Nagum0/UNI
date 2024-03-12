#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

int main() {
    printf("%ld\n", LONG_MAX);
    printf("%lld\n", LLONG_MAX);
    printf("%zu\n", sizeof(size_t));
    char s[4];
    printf("%zu\n", sizeof(s));

    int x = isspace(' ');
    printf("%d\n", x);

    if (x == 0) {
        printf("as\n");
    }

    return 0;
}
