#ifndef QUEUE_H
#define QUEUE_H

typedef int T;

typedef struct queue queue;

queue* new_queue(int max_size);
void free_queue(queue *q);
int empty(queue *q);
int full(queue *q);
int size(queue *q);
int enqueue(queue *q, T data);
int dequeue(queue *q, T *r);
int first(queue *q, T *r);
int last(queue *q, T *r);

#endif