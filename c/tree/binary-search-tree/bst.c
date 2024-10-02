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
        }
        else {
            current = &(*current)->right;
        }
    }
    *current = temp;
}

bool search(struct node* root, int key) {
    struct node* current = root;
    while (current != NULL) {
        if (current->key == key) {
            return true;
        }
        else if (current->key > key) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    return false;
}

int pop_minimum(struct node** root) {
    struct node** current = root;
    while (*current != NULL && (*current)->left != NULL) {
        current = &(*current)->left;
    }
    if (*current != NULL) {
        struct node* minimum = *current;
        int result = minimum->key;
        *current = minimum->right;
        free(minimum);
        return result;
    }
    return 0;
}

int pop_maximum(struct node** root) {
    struct node** current = root;
    while (current != NULL && (*current)->right != NULL) {
        current = &(*current)->right;
    }
    if (*current != NULL) {
        struct node* maximum = *current;
        int result = maximum->key;
        *current = maximum->left;
        free(maximum);
        return result;
    }
    return 0;
}

void delete(struct node** root, int key) {
    struct node** current = root;
    while (*current != NULL) {
        if ((*current)->key > key) {
            current = &(*current)->left;
        }
        else if ((*current)->key < key) {
            current = &(*current)->right;
        }
        else {
            break;
        }
    }
    if (*current != NULL) {
        // If it's a leaf node
        if ((*current)->left == NULL && (*current)->right == NULL) {
            free(*current);
            *current = NULL;
        }
        // If it has two children
        else if ((*current)->left != NULL && (*current)->right != NULL) {
            (*current)->key = pop_minimum(&(*current)->right);
        }
        // If it has one children
        else {
            struct node* node = *current;
            if ((*current)->left != NULL) {
                *current = (*current)->left;
            }
            else {
                *current = (*current)->right;
            }
            free(node);
        }
    }
}