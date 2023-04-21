#include <stdlib.h>
#include "list.h"

list* init_list() {
    list *l = (list*)malloc(sizeof(list));
    if (l) {
        l->head = l->tail = NULL;
        l->size = 0;
    }
}
     
void free_list(list *l) {
    if (!l) return;
    while (!empty(l))
        pop_back(l, NULL);
    free(l);
}

int empty(list *l) {
    if (!l) return 1;
    return l->head == NULL;
}

int size(list *l) {
    if (!l) return 0;
    return l->size;
}

int push_front(list *l, T data) {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    if (!l || !n)
        return 0;
    n->data = data;
    n->next = l->head;
    n->prev = NULL;
    if (empty(l))
        l->tail = n;
    else
        l->head->prev = n;
    l->head = n;
    l->size++;
    return 1;
}

int push_back(list *l, T data) {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    if (!l || !n)
        return 0;
    n->data = data;
    n->next = NULL;
    n->prev = l->tail;
    if (empty(l))
        l->head = n;
    else
        l->tail->next = n;
    l->tail = n;
    l->size++;
    return 1;
}

int pop_front(list *l, T *r) {
    if (!l || empty(l))
        return 0;
    if (r)
        *r = l->head->data;
    if (l->head == l->tail)
        l->tail = NULL;
    struct node *n = l->head;
    l->head = l->head->next;
    if (l->head)
        l->head->prev = NULL;
    free(n);
    l->size--;
    return 1;
}

int pop_back(list *l, T *r) {
    if (!l || empty(l))
        return 0;
    if (r)
        *r = l->tail->data;
    if (l->head == l->tail)
        l->head = NULL;
    struct node *n = l->tail;
    l->tail = l->tail->prev;
    if (l->tail)
        l->tail->next = NULL;
    free(n);
    l->size--;
    return 1;
}

int first(list *l, T *r) {
    if (!l || empty(l)) return 0;
    *r = l->head->data;
    return 1;
}

int last(list *l, T *r) {
    if (!l || empty(l)) return 0;
    *r = l->tail->data;
    return 1;
}