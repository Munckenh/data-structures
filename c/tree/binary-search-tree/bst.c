#include <stdlib.h>
#include <stdbool.h>
#include "bst.h"

void initialize(struct node** root) {
    *root = NULL;
}

void insert(struct node** root, int key) {
    struct node** current = root;
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = key;
    temp->left = NULL;
    temp->right = NULL;
    while (*current != NULL) {
        if ((*current)->key > key) {
            current = &(*current)->left;
        } else {
            current = &(*current)->right;
        }
    }
    *current = temp;
}

bool search(struct node* root, int key) {
    struct node* current = root;
    while (current != NULL) {
        if (current->key == key){
            return true;
        }
        else if (current->key > key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false;
}

struct node* pop_minimum(struct node** root) {
    struct node** current = root;
    while (*current != NULL && (*current)->left != NULL) {
        current = &(*current)->left;
    }
    struct node* minimum = *current;
    if (*current != NULL) {
        *current = minimum->right;
        minimum->right = NULL;
    }
    return minimum;
}

struct node* pop_maximum(struct node** root) {
    struct node** current = root;
    while (current != NULL && (*current)->right != NULL) {
        current = &(*current)->right;
    }
    struct node* maximum = *current;
    if (*current != NULL) {
        *current = maximum->left;
        maximum->left = NULL;
    }
    return maximum;
}