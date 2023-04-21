#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void post_order(struct node *root) {
	if (!root)
		return;
	post_order(root->left);
	post_order(root->right);
	printf("%d\n", root->data);
}

int main() {
	bst tree;
	bst_init(&tree);

	insert(&tree, 10);
	insert(&tree, 5);
	insert(&tree, 15);
	insert(&tree, 2);
	insert(&tree, 8);
	insert(&tree, 11);
	insert(&tree, 19);

	/*
			10
		   /  \
		  5    15
		 / \   / \
		2   8 11 19
	*/
	
	post_order(tree.root);

	delete(&tree, 8);
	delete(&tree, 15);

	/*
			10
		   /  \
		  5    19
		 /    /
		2    11
	*/

	post_order(tree.root);

	bst_free(&tree);
    return 0;
}