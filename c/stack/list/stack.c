#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>
#include "stack.h"

void initialize(struct stack* stack) {
    stack->top = NULL;
}

bool is_empty(struct stack* stack) {
    return (stack->top == NULL) ? true : false;
}

void push(struct stack* stack, int value) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    if (node != NULL) {
        node->data = value;
        node->next = stack->top;
        stack->top = node;
    }
    else {
        printf("Memory allocation failed!\n");
    }
}

int pop(struct stack* stack) {
    int result = INT_MAX;
    if (stack->top != NULL) {
        struct node* node = stack->top;
        result = node->data;
        stack->top = node->next;
        free(node);
    }
    return result;
}

int peek(struct stack* stack) {
    return (stack->top == NULL) ? INT_MAX : stack->top->data;
}