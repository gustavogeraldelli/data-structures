#ifndef BST_H
#define BST_H

typedef int T;

typedef struct bst bst;

bst* new_bst();
void free_bst(bst *tree);
void insert_bst(bst *tree, T data);
void delete_bst(bst *tree, T data);
int search_bst(bst *tree, T key);
void post_order_bst(bst *tree);

#endif