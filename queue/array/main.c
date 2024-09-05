#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main() {
    queue *q = init_queue();
    
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    int qfirst, qlast;
    first(q, &qfirst);
    last(q, &qlast);
    printf("%d %d\n", qfirst, qlast);

    dequeue(q, NULL);
    first(q, &qfirst);
    last(q, &qlast);
    printf("%d %d\n", qfirst, qlast);

    int removed;
    dequeue(q, &removed);
    printf("Item removed: %d\n", removed);

    dequeue(q, NULL);
    if (!dequeue(q, NULL))
        printf("Queue is empty.\n");

    free_queue(q);
    return 0;
}