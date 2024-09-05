#include <stdlib.h>
#include "stack.h"

stack* init_stack() {
    stack *s = (stack*)malloc(sizeof(stack));
    if (s) {
        s->arr = malloc(sizeof(T) * 2);
        s->top = 0;
        s->max = 2;
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
    return s->top == s->max;
}

int size(stack *s) {
    if (!s) return 0;
    return s->top;
}

int resize(stack *s, int new_max) {
    T *temp = malloc(sizeof(T) * new_max);
    if (!temp) 
        return 0;
    for (int i = 0; i < new_max; i++)
        temp[i] = s->arr[i];
    free(s->arr);
    s->arr = temp;
    s->max = new_max;
    return 1;
}

int push(stack *s, T data) {
    if (!s || (full(s) && !resize(s, s->max * 2))) 
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
    if (s->top > 0 && s->top <= s->max / 4)
        resize(s, s->max / 2);
    return 1;
}

int peek(stack *s, T *r) {
    if (!s || empty(s)) return 0;
    *r = s->arr[s->top - 1];
    return 1;
}
