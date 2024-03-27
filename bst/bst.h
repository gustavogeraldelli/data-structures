#ifndef BST_H
#define BST_H

typedef int T;

struct node {
    T data;
    struct node *left, *right;
};

typedef struct {
    struct node *root;
} bst;

void bst_init(bst *tree);
void bst_free(bst *tree);
void insert(bst *tree, T data);
void delete(bst *tree, T data);
int search(bst *tree, T key);

#endif