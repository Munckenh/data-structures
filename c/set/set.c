#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "set.h"

struct node* create_node(int value) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    if (node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    node->data = value;
    node->next = NULL;
    return node;
}

int cardinality(struct node* set) {
    struct node* current = set;
    int count;
    for (count = 0; current != NULL; current = current->next, ++count);
    return count;
}

bool contains(struct node* set, int value) {
    struct node* current = set;
    for (; current != NULL && current->data != value; current = current->next);
    return (current != NULL) ? true : false;
}

struct node* get_union(struct node* a, struct node* b) {
    struct node* result = NULL;
    struct node** tail = &result;
    while (a != NULL && b != NULL) {
        if (a->data < b->data) {
            *tail = create_node(a->data);
            a = a->next;
        }
        else if (a->data > b->data) {
            *tail = create_node(b->data);
            b = b->next;
        }
        else {
            *tail = create_node(a->data);
            a = a->next;
            b = b->next;
        }
        tail = &(*tail)->next;
    }
    if (a == NULL) {
        *tail = b;
    }
    else if (b == NULL) {
        *tail = a;
    }
    return result;
}

struct node* get_intersection(struct node* a, struct node* b) {
    struct node* result = NULL;
    struct node** tail = &result;
    while (a != NULL && b != NULL) {
        if (a->data < b->data) {
            a = a->next;
        }
        else if (a->data > b->data) {
            b = b->next;
        }
        else {
            *tail = create_node(a->data);
            tail = &(*tail)->next;
            a = a->next;
            b = b->next;
        }
    }
    return result;
}