#include <stdlib.h>
#include "list.h"
#include <stdio.h>

list* init_list() {
    list *l = (list*)malloc(sizeof(list));
    struct node *n = (struct node*)malloc(sizeof(struct node));
    if (l) {
        n->next = n->prev = l->sentinel = n;
        l->size = 0;
    }
}

void free_list(list *l) {
    if (!l) return;
    while (!empty(l))
        pop_back(l, NULL);
    free(l->sentinel);
    free(l);
}

int empty(list *l) {
    if (!l) return 1;
    return l->sentinel == l->sentinel->next;
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
    n->next = l->sentinel->next;
    n->prev = l->sentinel;
    l->sentinel->next = n;
    n->next->prev = n;
    l->size++;
    return 1;
}

int push_back(list *l, T data) {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    if (!l || !n)
        return 0;
    n->data = data;
    n->prev = l->sentinel->prev;
    n->next = l->sentinel;
    l->sentinel->prev = n;
    n->prev->next = n;
    l->size++;
    return 1;
}

int pop_front(list *l, T *r) {
    if (!l || empty(l))
        return 0;
    if (r)
        *r = l->sentinel->next->data;
    struct node *n = l->sentinel->next;
    n->prev->next = n->next;
    n->next->prev = n->prev;
    free(n);
    l->size--;
    return 1;
}

int pop_back(list *l, T *r) {
    if (!l || empty(l))
        return 0;
    if (r)
        *r = l->sentinel->prev->data;
    struct node *n = l->sentinel->prev;
    n->next->prev = n->prev;
    n->prev->next = n->next;
    free(n);
    l->size--;
    return 1;
}

int first(list *l, T *r) {
    if (!l || empty(l)) return 0;
    *r = l->sentinel->next->data;
    return 1;
}

int last(list *l, T *r) {
    if (!l || empty(l)) return 0;
    *r = l->sentinel->prev->data;
    return 1;
}