#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node {
    T data;
    struct node *next;
};

struct list {
    struct node *head, *tail;
    int size;
};

list* new_list() {
    list *l = (list*)malloc(sizeof(list));
    if (l) {
        l->head = NULL;
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
    if (empty(l))
        l->tail = n;
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
    free(n);
    l->size--;
    return 1;
}

int pop_back(list *l, T *r) {
    if (!l || empty(l))
        return 0;
    if (r)
        *r = l->tail->data;
    struct node *n = l->head;
    if (l->head == l->tail)
        l->head = l->tail = NULL;
    else {
        struct node *prev = NULL;
        while (n->next) {
            prev = n;
            n = n->next;
        }
        prev->next = NULL;
        l->tail = prev;
    }
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

void print_list(list *l) {
    if (!l || empty(l)) return;
    struct node *n = l->head;
    while (n) {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}