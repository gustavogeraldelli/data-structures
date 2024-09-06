#ifndef AVL_H
#define AVL_H

typedef int T;
typedef struct avl avl;

avl* new_avl();
void free_avl(avl *tree);
void insert_avl(avl *tree, T data);
void delete_avl(avl *tree, T data);
int search_avl(avl *tree, T key);
void post_order_avl(avl *tree);

#endif