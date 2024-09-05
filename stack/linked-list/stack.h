#ifndef STACK_H
#define STACK_H

typedef int T;

struct node {
    T data;
    struct node *next;
};

typedef struct {
    struct node *top;
    int size;
} stack;

stack* init_stack();
void free_stack(stack *s);
int empty(stack *s);
int size(stack *s);
int push(stack *s, T data);
int pop(stack *s, T *r);
int peek(stack *s, T *r);

#endif
