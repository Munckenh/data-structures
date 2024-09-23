#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

struct queue {
    int front;
    int rear;
    int size;
    int* values;
};

void initialize(struct queue*, int size);
void enqueue(struct queue*, int);
int dequeue(struct queue*);
int peek(struct queue*);
bool is_empty(struct queue*);
bool is_full(struct queue*);

#endif