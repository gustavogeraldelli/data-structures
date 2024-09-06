#include <stdlib.h>
#include "queue.h"

struct node {
    T data;
    struct node *next;
};

struct queue {
    struct node *front, *rear;
    int size;
};

queue* new_queue() {
    queue *q = (queue*)malloc(sizeof(queue));
    if (q) {
        q->front = q->rear = NULL;
        q->size = 0;
    }
    return q;
}

void free_queue(queue *q) {
    if (!q) return;
    while (!empty(q))
        dequeue(q, NULL);
    free(q);
}

int empty(queue *q) {
    if (!q) return 1;
    return q->front == NULL;
}

int size(queue *q) {
    if (!q) return 0;
    return q->size;
}

int enqueue(queue *q, T data) {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    if (!q || !n)
        return 0;
    n->data = data;
    n->next = NULL;
    if (q->rear)
        q->rear->next = n;
    else
        q->front = n;
    q->rear = n;
    q->size++;
    return 1;
}

int dequeue(queue *q, T *r) {
    if (!q || empty(q))
        return 0;
    if (r) 
        *r = q->front->data;
    struct node *n = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(n);
    q->size--;
    return 1;
}

int first(queue *q, T *r) {
    if (!q || empty(q)) return 0;
    *r = q->front->data;
    return 1;
}

int last(queue *q, T *r) {
    if (!q || empty(q)) return 0;
    *r = q->rear->data;
    return 1;
}