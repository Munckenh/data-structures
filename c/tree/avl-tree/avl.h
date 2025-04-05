#ifndef AVL_TREE_H
#define AVL_TREE_H

typedef struct node {
    int key;
    struct node* left;
    struct node* right;
    int height;
} Node;

int max(int a, int b);
int height(Node* node);
int balance_factor(Node* node);
Node* create_node(int key);
Node* rotate_left(Node* node);
Node* rotate_right(Node* node);
void insert(Node** root, int key);

#endif