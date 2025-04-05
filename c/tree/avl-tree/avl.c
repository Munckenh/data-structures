#include <stdlib.h>
#include "avl.h"

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node* node) {
    return (node != NULL) ? node->height : 0;
}

int balance_factor(Node* node) {
    return (node != NULL) ? height(node->left) - height(node->right) : 0;
}

Node* create_node(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node != NULL) {
        node->key = key;
        node->left = NULL;
        node->right = NULL;
        node->height = 1;
    }
    return node;
}

Node* rotate_right(Node* root) {
    Node* x = root->left;
    Node* t2 = x->right;
    x->right = root;
    root->left = t2;
    root->height = max(height(root->left), height(root->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node* rotate_left(Node* root) {
    Node* y = root->right;
    Node* t2 = y->left;
    y->left = root;
    root->right = t2;
    root->height = max(height(root->left), height(root->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

void insert(Node** root, int key) {
    // Insert like in a normal binary search tree
    if (*root == NULL) {
        *root = create_node(key);
        return;
    }

    if (key < (*root)->key) {
        insert(&(*root)->left, key);
    }
    else if (key > (*root)->key) {
        insert(&(*root)->right, key);
    }
    else {
        return;
    }

    // Update height
    (*root)->height = max(height((*root)->left), height((*root)->right)) + 1;

    // Rotate if unbalanced
    int bf = balance_factor(*root);
    if (bf > 1 && key < (*root)->left->key) {
        *root = rotate_right(*root);
    } else if (bf < -1 && key >(*root)->right->key) {
        *root = rotate_left(*root);
    } else if (bf > 1 && key > (*root)->left->key) {
        (*root)->left = rotate_left((*root)->left);
        *root = rotate_right(*root);
    } else if (bf < -1 && key < (*root)->right->key) {
        (*root)->right = rotate_right((*root)->right);
        *root = rotate_left(*root);
    }
}