#ifndef QUE_H
#define QUE_H

typedef struct Queue Queue;
Queue *create_queue();
void free_queue(Queue *que);
void queue_add(Queue *que, int x);
int queue_remove(Queue *que);
void queue_display(Queue *que);
int queue_first(Queue *que);
int queue_len(Queue *que);
int queue_is_empty(Queue *que);
void queue_set_empty(Queue *que);

#endif