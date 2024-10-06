#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

struct node {
    int data;
    struct node* next;
};

struct stack {
    struct node* top;
};

void initialize(struct stack*);
bool is_empty(struct stack*);
void push(struct stack*, int);
int pop(struct stack*);
int peek(struct stack*);
void sort(struct stack*);

#endif