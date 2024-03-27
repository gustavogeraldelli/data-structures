#ifndef AVL_H
#define AVL_H

typedef int T;

struct node {
    T data;
    struct node *left, *right;
    int height;
};

typedef struct {
    struct node *root;
} avl;

void avl_init(avl *tree);
void avl_free(avl *tree);
void insert(avl *tree, T data);
void delete(avl *tree, T data);
int search(avl *tree, T key);

#endif