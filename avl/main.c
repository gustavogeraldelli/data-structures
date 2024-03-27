#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

void post_order(struct node *root) {
	if (!root)
		return;
	post_order(root->left);
	post_order(root->right);
	printf("%d\n", root->data);
}

int main() {
	avl tree;
	avl_init(&tree);

	insert(&tree, 1);
	insert(&tree, 2);
	insert(&tree, 3);
	insert(&tree, 4);
	insert(&tree, 5);
	insert(&tree, 6);
	
	// A BST would look like 1 -> 2 -> 3 -> 4 -> 5 -> 6, post_order would print 6 5 4 3 2 1
	post_order(tree.root);
	printf("\n");

	delete(&tree, 4);
	delete(&tree, 3);
	delete(&tree, 6);

	post_order(tree.root);

	avl_free(&tree);
    return 0;
}