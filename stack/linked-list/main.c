#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
	stack *s = new_stack();

    push(s, 5);
    push(s, 4);
    push(s, 3); 
    push(s, 2);
    push(s, 1);

    /*
        Top
        1
        2
        3
        4
        5
    */
    
    int top;
    peek(s, &top);
    printf("Top: %d\n", top);

    int popped;
	pop(s, NULL);
    pop(s, &popped);
    printf("Popped: %d\n", popped);

    /*
        Top
        3
        4
        5
    */
    
    peek(s, &top);
    printf("Top: %d\n", top);

    free_stack(s);
	
    return 0;
}
