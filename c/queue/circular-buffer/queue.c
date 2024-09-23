#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "queue.h"

void initialize(struct queue* q, int size) {
    q->size = size;
    q->values = (int*)malloc(sizeof(int) * size);
    q->front = -1;
    q->rear = -1;
}

void enqueue(struct queue* q, int value) {
    if (is_empty(q)) {
        q->front = 0;
        q->rear = 0;
        q->values[0] = value;
    }
    else {
        if (is_full(q)) {
            q->size *= 2;
            q->values = (int*)realloc(q->values, q->size);
        }
        q->values[++q->rear] = value;
    }
}

int dequeue(struct queue* q) {
    if (is_empty(q))
        return INT_MIN;
    if (q->front == q->rear) {
        int result = q->values[q->front];
        q->front = -1;
        q->rear = -1;
        return result;
    }
    return q->values[q->front++];
}

int peek(struct queue* q) {
    if (is_empty(q))
        return INT_MIN;
    return q->values[q->front];
}

bool is_empty(struct queue* q) {
    return q->front == -1 && q->rear == -1;
}

bool is_full(struct queue* q) {
    return (q->rear + 1) % q->size == q->front;
}