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
struct node* pop_minimum(struct node**);
struct node* pop_maximum(struct node**);

#endif