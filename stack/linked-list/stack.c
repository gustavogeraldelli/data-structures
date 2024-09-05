#include <stdlib.h>
#include "stack.h"

stack* init_stack() {
    stack *s = (stack*)malloc(sizeof(stack));
    if (s) {
        s->top = NULL;
        s->size = 0;
    }
    return s;
}

void free_stack(stack *s) {
    if (!s) return;
    while (!empty(s))
        pop(s, NULL);
    free(s);
}

int empty(stack *s) {
    if (!s) return 1;
    return s->top == NULL;
}

int size(stack *s) {
    if (!s) return 0;
    return s->size;
}

int push(stack *s, T data) {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    if (!s || !n)
        return 0;
    n->data = data;
    n->next = s->top;
    s->top = n;
    s->size++;
    return 1;
}

int pop(stack *s, T *r) {
    if (!s || empty(s))
        return 0;
    if (r)
        *r = s->top->data;
    struct node *n = s->top;
    s->top = n->next;
    free(n);
    s->size--;
    return 1;
}

int peek(stack *s, T *r) {
    if (!s || empty(s)) return 0;
    *r = s->top->data;
    return 1;
}
