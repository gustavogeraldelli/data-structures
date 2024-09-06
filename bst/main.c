#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main() {
	bst *tree = new_bst();

	insert_bst(tree, 10);
	insert_bst(tree, 5);
	insert_bst(tree, 15);
	insert_bst(tree, 2);
	insert_bst(tree, 8);
	insert_bst(tree, 11);
	insert_bst(tree, 19);

	/*
			10
		   /  \
		  5    15
		 / \   / \
		2   8 11 19
	*/
	
	post_order_bst(tree);
	
	delete_bst(tree, 8);
	delete_bst(tree, 15);

	/*
			10
		   /  \
		  5    19
		 /    /
		2    11
	*/

	post_order_bst(tree);

	free_bst(tree);
    return 0;
}