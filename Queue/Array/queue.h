#ifndef QUEUE_H
#define QUEUE_H

#define MAX 100

typedef int T;

typedef struct {
    T *arr;
    int front, rear;
    int size;
} queue;

queue* init_queue();
void free_queue(queue *q);
int empty(queue *q);
int full(queue *q);
int size(queue *q);
int enqueue(queue *q, T data);
int dequeue(queue *q, T *r);
int first(queue *q, T *r);
int last(queue *q, T *r);

#endif