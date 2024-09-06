#include <stdlib.h>
#include "queue.h"

struct queue {
    T *arr;
    int front, rear;
    int max_size, size;
};

queue* new_queue(int max_size) {
    queue *q = (queue*)malloc(sizeof(queue));
    if (q) {
        q->arr = malloc(sizeof(T) * max_size);
        q->front = q->size = 0;
        q->rear = -1;
        q->max_size = max_size;
    }
    return q;
}

void free_queue(queue *q) {
    if (!q) return;
    free(q->arr);
    free(q);
}

int empty(queue *q) {
    if (!q) return 1;
    return q->size == 0;
}

int full(queue *q) {
    if (!q) return 0;
    return q->size == q->max_size;
}

int size(queue *q) {
    if (!q) return 0;
    return q->size;
}

int enqueue(queue *q, T data) {
    if (!q || full(q))
        return 0;
    q->rear = (q->rear + 1) % q->max_size;
    q->arr[q->rear] = data;
    q->size++;
    return 1;
}

int dequeue(queue *q, T *r) {
    if (!q || empty(q))
        return 0;
    if (r)
        *r = q->arr[q->front];
    q->front = (q->front + 1) % q->max_size;
    q->size--;
    return 1;
}

int first(queue *q, T *r) {
    if (!q || empty(q)) return 0;
    *r = q->arr[q->front];
    return 1;
}

int last(queue *q, T *r) {
    if (!q || empty(q)) return 0;
    *r = q->arr[q->rear];
    return 1;
}