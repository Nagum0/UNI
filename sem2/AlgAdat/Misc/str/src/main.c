#include <stdio.h>
#include <stdlib.h>

#include ".\m_str\m_str.h"

int main(void) {
    String *title = new_string("This is some sample text!");
    String *p1 = new_string("This is a paragraph.");
    String *article = push_string(title, p1);

    size_t arr_size = 3;
    String *arr[arr_size];
    arr[0] = new_string("t1");
    arr[1] = new_string("t2");
    arr[2] = new_string("t3");

    print_string(arr[0]);
    print_string(arr[1]);
    print_string(arr[2]);

    free_string(title);
    free_string(p1);
    free_string(article);
    free_arr_string(arr, arr_size);

    return EXIT_SUCCESS;
}