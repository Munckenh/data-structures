#ifndef PARTIALLY_ORDERED_TREE_H
#define PARTIALLY_ORDERED_TREE_H

struct tree {
    int* array;
    int size;
    int last_index;
};

void initialize(struct tree*, int);
int get_parent(int);
int get_left_child(int);
int get_right_child(int);
void push(struct tree*, int);
int pop(struct tree*);

#endif