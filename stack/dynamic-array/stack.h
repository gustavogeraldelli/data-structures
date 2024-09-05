#ifndef STACK_H
#define STACK_H

typedef int T;

typedef struct {
    T *arr;
    int top;
    int max;
} stack;

stack* init_stack();
void free_stack(stack *s);
int empty(stack *s);
int full(stack *s);
int push(stack *s, T data);
int pop(stack *s, T *r);
int peek(stack *s, T *r);

#endif
