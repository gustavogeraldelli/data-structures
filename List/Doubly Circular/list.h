#ifndef LIST_H
#define LIST_H

typedef int T;

struct node {
    T data;
    struct node *next, *prev;
};

typedef struct {
    struct node *head;
    int size;
} list;

list* init_list();
void free_list(list *l);
int empty(list *l);
int size(list *l);
int push_front(list *l, T data);
int push_back(list *l, T data);
int pop_front(list *l, T *r);
int pop_back(list *l, T *r);
int first(list *l, T *r);
int last(list *l, T *r);

#endif