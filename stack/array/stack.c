#include <stdlib.h>
#include "stack.h"

struct stack {
    T *arr;
    int top;
};

stack* new_stack() {
    stack *s = (stack*)malloc(sizeof(stack));
    if (s) {
        s->arr = malloc(sizeof(T) * MAX);
        s->top = 0;
    }
    return s;
}

void free_stack(stack *s) {
    if (!s) return;
    free(s->arr);
    free(s);
}

int empty(stack *s) {
    if (!s) return 1;
    return s->top == 0;
}

int full(stack *s) {
    if (!s) return 0;
    return s->top == MAX;
}

int size(stack *s) {
    if (!s) return 0;
    return s->top;
}

int push(stack *s, T data) {
    if (!s || full(s))
        return 0;
    s->arr[s->top++] = data;
    return 1;
}

int pop(stack *s, T *r) {
    if (!s || empty(s))
        return 0;
    if (r)
        *r = s->arr[s->top - 1];
    s->top--;
    return 1;
}

int peek(stack *s, T *r) {
    if (!s || empty(s)) return 0;
    *r = s->arr[s->top - 1];
    return 1;
}
