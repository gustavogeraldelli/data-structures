#include <stdlib.h>
#include "bst.h"

void bst_init(bst *tree) {
    tree->root = NULL;
}

void _bst_free(struct node *root) {
    if (!root) return;
    _bst_free(root->left);
    _bst_free(root->right);
    free(root);
}

void bst_free(bst *tree) {
    _bst_free(tree->root);
}

struct node* new_node(T data) {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

struct node* _insert(struct node *root, T data) {
    if (!root)
        return new_node(data);
    
    if (data < root->data)
        root->left = _insert(root->left, data);
    else if (data > root->data)
        root->right = _insert(root->right, data);
    
    return root;
}

void insert(bst *tree, T data) {
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
            root->right = _delete(root->right, n->data);
        }
    }
    else if (data < root->data)
        root->left = _delete(root->left, data);
    else
        root->right = _delete(root->right, data);

    return root;
}

void delete(bst *tree, T data) {
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

int search(bst *tree, T key) {
    return _search(tree->root, key);
}
