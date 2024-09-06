#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

struct node {
    T data;
    struct node *left, *right;
    int height;
};

struct avl {
    struct node *root;
};

avl* new_avl() {
    avl *tree = (avl*)malloc(sizeof(avl));
    if (tree)
        tree->root = NULL;
    return tree;
}

void _free_avl(struct node *root) {
    if (!root) return;
    _free_avl(root->left);
    _free_avl(root->right);
    free(root);
}

void free_avl(avl *tree) {
    if (!tree) return;
    _free_avl(tree->root);
}

struct node* new_node(T data) {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = n->right = NULL;
    n->height = 1;
    return n;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct node *n) {
    return n ? n->height : 0;
}

int balance(struct node *n) {
    return n ? height(n->left) - height(n->right) : 0;
}

struct node* left_rotate(struct node *n) {
    struct node *right_node = n->right;
    struct node *center_node = right_node->left;
    right_node->left = n;
    n->right = center_node;
    n->height = 1 + max(height(n->left), height(n->right));
    right_node->height = 1 + max(height(right_node->left), height(right_node->right));
    return right_node;
}

struct node* right_rotate(struct node *n) {
    struct node *left_node = n->left;
    struct node *center_node = left_node->right;
    left_node->right = n;
    n->left = center_node;
    n->height = 1 + max(height(n->left), height(n->right));
    left_node->height = 1 + max(height(left_node->left), height(left_node->right));
    return left_node;
}

struct node* _insert_avl(struct node *root, T data) {
    if (!root)
        return new_node(data);
    
    if (data < root->data)
        root->left = _insert_avl(root->left, data);
    else if (data > root->data)
        root->right = _insert_avl(root->right, data);
    else
        return root;
    
    root->height = 1 + max(height(root->left), height(root->right));

    int bal = balance(root);

    if (bal > 1) {
        if (data > root->left->data)
            root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    else if (bal < -1) {
        if (data < root->right->data)
            root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

void insert_avl(avl *tree, T data) {
    if (!tree) return;
    tree->root = _insert_avl(tree->root, data);
}

struct node* get_min(struct node *root) {
    if (!root->left)
        return root;
    return get_min(root->left);
}

struct node* _delete_avl(struct node *root, T data) {
    if (!root)
        return NULL;
    
    if (data == root->data) {
        if (!root->left && !root->right) {
            free(root);
            root = NULL;
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
            root->right = _delete_avl(root->right, n->data);
        }
    }
    else if (data < root->data)
        root->left = _delete_avl(root->left, data);
    else
        root->right = _delete_avl(root->right, data);

    if (!root)
        return root;
    
    root->height = 1 + max(height(root->left), height(root->right));

    int bal = balance(root);

    if (bal > 1) {
        if (balance(root->left) < 0)
            root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    else if (bal < -1) {
        if (balance(root->right) > 0)
            root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

void delete_avl(avl *tree, T data) {
    if (!tree) return;
    tree->root = _delete_avl(tree->root, data);
}

int _search_avl(struct node *root, T key) {
    if (!root)
        return 0;

    if (key == root->data)
        return 1;
    else if (key < root->data)
        return _search_avl(root->left, key);
    else if (key > root->data)
        return _search_avl(root->right, key);

}

int search_avl(avl *tree, T key) {
    if (!tree) return 0;
    return _search_avl(tree->root, key);
}

void _post_order_avl(struct node *root) {
	if (!root)
		return;
	_post_order_avl(root->left);
	_post_order_avl(root->right);
	printf("%d ", root->data);
}

void post_order_avl(avl *tree) {
    if (!tree) return;
    _post_order_avl(tree->root);
    printf("\n");
}