#ifndef SET_H
#define SET_H

#include <stdbool.h>

struct node {
    int data;
    struct node* next;
};

struct node* create_node(int);
int cardinality(struct node*);
bool contains(struct node*, int);
struct node* get_union(struct node*, struct node*);
struct node* get_intersection(struct node*, struct node*);

#endif