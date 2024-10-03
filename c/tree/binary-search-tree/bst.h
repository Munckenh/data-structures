#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdbool.h>

struct node {
    int key;
    struct node* left;
    struct node* right;
};

void initialize(struct node**);
void insert(struct node**, int);
bool search(struct node*, int);
int pop_minimum(struct node**);
int pop_maximum(struct node**);
void delete(struct node**, int);
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);

#endif