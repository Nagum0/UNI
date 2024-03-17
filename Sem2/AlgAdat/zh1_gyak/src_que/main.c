#include <stdio.h>
#include "queue\que.h"

int main(void) {
    Queue *q = create_queue();
    queue_add(q, 7);
    queue_add(q, 12);
    queue_add(q, 69);
    queue_display(q);
    queue_remove(q);
    queue_display(q);
    printf("First value: %d\n", queue_first(q));
    printf("Queue length: %d\n", queue_len(q));
    queue_set_empty(q);
    printf("Is queue empty: %d\n", queue_is_empty(q));
    queue_add(q, 420);
    queue_display(q);
    free_queue(q);
    return 0;
}