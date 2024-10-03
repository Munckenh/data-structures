#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "stack.h"

void initialize(struct stack* stack, int size) {
    stack->array = (int*)malloc(sizeof(int) * size);
    stack->top = -1;
    stack->size = size;
}

bool is_empty(struct stack* stack) {
    return (stack->top == -1) ? true : false;
}

void push(struct stack* stack, int value) {
    if (stack->top < stack->size - 1) {
        stack->array[++stack->top] = value;
    }
}

int pop(struct stack* stack) {
    int result = INT_MAX;
    if (stack->top != -1) {
        result = stack->array[stack->top--];
    }
    return result;
}

int peek(struct stack* stack) {
    return (stack->top == -1) ? INT_MAX : stack->array[stack->top];
}
