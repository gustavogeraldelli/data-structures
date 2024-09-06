#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main() {
	avl *tree = new_avl();

	insert_avl(tree, 1);
	insert_avl(tree, 2);
	insert_avl(tree, 3);
	insert_avl(tree, 4);
	insert_avl(tree, 5);
	insert_avl(tree, 6);
	
	// A BST would look like 1 -> 2 -> 3 -> 4 -> 5 -> 6, post_order would print 6 5 4 3 2 1
	post_order_avl(tree);

	delete_avl(tree, 4);
	delete_avl(tree, 3);
	delete_avl(tree, 6);

	post_order_avl(tree);

	free_avl(tree);
    return 0;
}