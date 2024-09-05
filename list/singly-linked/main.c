#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void print_list(list *l) {
    struct node *n = l->head;
    while (n) {
        printf("%d\n", n->data);
        n = n->next;
    }
}

int main() {
    list *l = init_list();

    push_back(l, 10);
    push_front(l, 44);
    push_back(l, 12);
    push_front(l, 25);
    
    print_list(l);

    int f, b;
    pop_front(l, &f);
    pop_back(l, &b);
    printf("Popped %d from the front\n", f);
    printf("Popped %d from the back\n", b);
    print_list(l);

    while (pop_back(l, &b))
        printf("Popped %d\n", b);

    if (!pop_front(l, NULL))
        printf("List is empty\n");

    push_back(l, 8);
    first(l, &f);
    last(l, &b);
    printf("First: %d\n", f);
    printf("Last: %d\n", b);

    print_list(l);

    free_list(l);
    return 0;
}
