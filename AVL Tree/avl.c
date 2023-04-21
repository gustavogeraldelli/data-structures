#include <stdlib.h>
#include "avl.h"

void avl_init(avl *tree) {
    tree->root = NULL;
}

void _avl_free(struct node *root) {
    if (!root) return;
    _avl_free(root->left);
    _avl_free(root->right);
    free(root);
}

void avl_free(avl *tree) {
    _avl_free(tree->root);
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

struct node* _insert(struct node *root, T data) {
    if (!root)
        return new_node(data);
    
    if (data < root->data)
        root->left = _insert(root->left, data);
    else if (data > root->data)
        root->right = _insert(root->right, data);
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

void insert(avl *tree, T data) {
    tree->root = _insert(tree->root, data);
}

struct node* get_min(struct node *root) {
    if (!root->left)
        return root;
    return get_min(root->left);
}

struct node*_delete(struct node *root, T data) {
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
            root->right = _delete(root->right, n->data);
        }
    }
    else if (data < root->data)
        root->left = _delete(root->left, data);
    else
        root->right = _delete(root->right, data);

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

void delete(avl *tree, T data) {
    tree->root = _delete(tree->root, data);
}

int _search(struct node *root, T key) {
    if (!root)
        return 0;

    if (key == root->data)
        return 1;
    else if (key < root->data)
        return _search(root->left, key);
    else if (key > root->data)
        return _search(root->right, key);

}

int search(avl *tree, T key) {
    return _search(tree->root, key);
}
