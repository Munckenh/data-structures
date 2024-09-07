#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "stack.h"

void test() {
    struct stack* stack;
    initialize(stack);
    assert(stack->top == NULL);
    assert(is_empty(stack));
    push(stack, 10);
    assert(!is_empty(stack));
    assert(peek(stack) == 10);
    push(stack, 20);
    assert(peek(stack) == 20);
    assert(pop(stack) == 20);
    assert(peek(stack) == 10);
    assert(pop(stack) == 10);
    assert(pop(stack) == INT_MAX);
}

int main() {
    test();
    return 0;
}