#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

struct stack {
    int* array;
    int top;
    int size;
};

void initialize(struct stack*, int);
bool is_empty(struct stack*);
void push(struct stack*, int);
int pop(struct stack*);
int peek(struct stack*);

#endif