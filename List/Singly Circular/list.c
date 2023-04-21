#include <stdlib.h>
#include "list.h"
#include <stdio.h>

list* init_list() {
    list *l = (list*)malloc(sizeof(list));
    if (l) {
        l->tail = NULL;
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
    return l->tail == NULL;
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
    if (empty(l)) {
        n->next = n;
        l->tail = n;
    }
    else {
        n->next = l->tail->next;
        l->tail->next = n;
    }
    l->size++;
    return 1;
}

int push_back(list *l, T data) {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    if (!l || !n)
        return 0;
    n->data = data;
    if (empty(l)) {
        n->next = n;
        l->tail = n;
    }
    else {
        n->next = l->tail->next;
        l->tail->next = n;
        l->tail = n;
    }
    l->size++;
    return 1;
}

int pop_front(list *l, T *r) {
    if (!l || empty(l))
        return 0;
    if (r)
        *r = l->tail->next->data;
    struct node *n = l->tail->next;
    if (l->tail == l->tail->next)
        l->tail = NULL;
    else
        l->tail->next = l->tail->next->next;
    free(n);
    l->size--;
    return 1;
}

int pop_back(list *l, T *r) {
    if (!l || empty(l))
        return 0;
    if (r)
        *r = l->tail->data;
    struct node *n = l->tail;
    if (l->tail == l->tail->next)
        l->tail = NULL;
    else {
        struct node *prev = l->tail;
        while (prev->next != l->tail)
            prev = prev->next;
        prev->next = l->tail->next;
        l->tail = prev;
    }
    free(n);
    l->size--;
    return 1;
}

int first(list *l, T *r) {
    if (!l || empty(l)) return 0;
    *r = l->tail->next->data;
    return 1;
}

int last(list *l, T *r) {
    if (!l || empty(l)) return 0;
    *r = l->tail->data;
    return 1;
}