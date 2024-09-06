#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

struct node {
    T data;
    struct node *left, *right;
};

struct bst {
    struct node *root;
};

bst* new_bst() {
    bst *tree = (bst*)malloc(sizeof(bst));
    if (tree)
        tree->root = NULL;
    return tree;
}

void _free_bst(struct node *root) {
    if (!root) return;
    _free_bst(root->left);
    _free_bst(root->right);
    free(root);
}

void free_bst(bst *tree) {
    if (!tree) return;
    _free_bst(tree->root);
}

struct node* new_node(T data) {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

struct node* _insert_bst(struct node *root, T data) {
    if (!root)
        return new_node(data);
    
    if (data < root->data)
        root->left = _insert_bst(root->left, data);
    else if (data > root->data)
        root->right = _insert_bst(root->right, data);
    
    return root;
}

void insert_bst(bst *tree, T data) {
    if (!tree) return;
    tree->root = _insert_bst(tree->root, data);
}

struct node* get_min(struct node *root) {
    if (!root->left)
        return root;
    return get_min(root->left);
}

struct node*_delete_bst(struct node *root, T data) {
    if (!root)
        return NULL;
    
    if (data == root->data) {
        if (!root->left && !root->right) {
            free(root);
            return NULL;
        }
        else if (!root->left) {
            struct node* n = root;
            root = root->right;
            free(n);
        }
        else if (!root->right) {
            struct node* n = root;
            root = root->left;
            free(n);
        }
        else {
            struct node* n = get_min(root->right);
            root->data = n->data;
            root->right = _delete_bst(root->right, n->data);
        }
    }
    else if (data < root->data)
        root->left = _delete_bst(root->left, data);
    else
        root->right = _delete_bst(root->right, data);

    return root;
}

void delete_bst(bst *tree, T data) {
    if (!tree) return;
    tree->root = _delete_bst(tree->root, data);
}

int _search_bst(struct node *root, T key) {
    if (!root)
        return 0;

    if (key == root->data)
        return 1;
    else if (key < root->data)
        return _search_bst(root->left, key);
    else if (key > root->data)
        return _search_bst(root->right, key);

}

int search_bst(bst *tree, T key) {
    if (!tree) return 0;
    return _search_bst(tree->root, key);
}

void _post_order_bst(struct node *root) {
	if (!root)
		return;
	_post_order_bst(root->left);
	_post_order_bst(root->right);
	printf("%d ", root->data);
}

void post_order_bst(bst *tree) {
    if (!tree) return;
	_post_order_bst(tree->root);
    printf("\n");
}