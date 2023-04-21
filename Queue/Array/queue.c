#include <stdlib.h>
#include "queue.h"

queue* init_queue() {
    queue *q = (queue*)malloc(sizeof(queue));
    if (q) {
        q->arr = malloc(sizeof(T) * MAX);
        q->front = q->rear = q->size = 0;
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
    return q->size == MAX;
}

int size(queue *q) {
    if (!q) return 0;
    return q->size;
}

int enqueue(queue *q, T data) {
    if (!q || full(q))
        return 0;
    q->arr[q->rear] = data;
    q->rear = (q->rear + 1) % MAX;
    q->size++;
    return 1;
}

int dequeue(queue *q, T *r) {
    if (!q || empty(q))
        return 0;
    q->front = (q->front + 1) % MAX;
    if (r)
        *r = q->arr[q->front];
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
    *r = q->arr[(q->rear - 1) % MAX];
    return 1;
}