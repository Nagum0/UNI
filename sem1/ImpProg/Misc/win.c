#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int width = 30;
    int height = 10;

    // Clear the screen
    system("clear"); // For Linux/macOS
    // system("cls"); // For Windows

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                putchar('*');
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }

    return 0;
}
