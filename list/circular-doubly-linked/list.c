#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node {
    T data;
    struct node *next, *prev;
};

struct list {
    struct node *head;
    int size;
};

list* new_list() {
    list *l = (list*)malloc(sizeof(list));
    if (l) {
        l->head = NULL;
        l->size = 0;
    }
    return l;
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
    if (empty(l)) {
        n->next = n->prev = n;
        l->head = n;
    }
    else {
        n->next = l->head;
        n->prev = l->head->prev;
        l->head->prev->next = n;
        l->head->prev = n;
        l->head = n;
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
        n->next = n->prev = n;
        l->head = n;
    }
    else {
        n->next = l->head;
        n->prev = l->head->prev;
        l->head->prev->next = n;
        l->head->prev = n;
    }
    l->size++;
    return 1;
}

int pop_front(list *l, T *r) {
    if (!l || empty(l))
        return 0;
    if (r)
        *r = l->head->data;
    struct node *n = l->head;
    if (l->head->next == l->head)
        l->head = NULL;
    else {
        l->head->prev->next = l->head->next;
        l->head->next->prev = l->head->prev;
        l->head = l->head->next;
    }
    free(n);
    l->size--;
    return 1;
}

int pop_back(list *l, T *r) {
    if (!l || empty(l))
        return 0;
    if (r)
        *r = l->head->prev->data;
    struct node *n = l->head->prev;
    if (l->head->next == l->head)
        l->head = NULL;
    else {
        l->head->prev->prev->next = l->head;
        l->head->prev = l->head->prev->prev;
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
    *r = l->head->prev->data;
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