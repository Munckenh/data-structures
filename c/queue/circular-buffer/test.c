#include <limits.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

int main() {
    struct queue q;
    // Test `initialize()`
    initialize(&q, 1);
    assert(q.size == 1);
    assert(q.front = -1);
    assert(q.rear == -1);
    assert(q.values != NULL);

    // Test `enqueue()`
    enqueue(&q, 10);
    assert(q.values[0] == 10);
    enqueue(&q, 20);
    assert(q.values[1] == 20);
    enqueue(&q, 30);
    assert(q.values[2] == 30);
    assert(q.size == 4);

    // Test `dequeue()`
    assert(dequeue(&q) == 10);
    assert(dequeue(&q) == 20);
    assert(dequeue(&q) == 30);
    assert(dequeue(&q) == INT_MIN);

    // Test `peek()`
    enqueue(&q, 10);
    enqueue(&q, 20);
    assert(peek(&q) == 10);
    dequeue(&q);
    assert(peek(&q) == 20);
    dequeue(&q);
    assert(peek(&q) == INT_MIN);

    // Test `is_empty()`
    assert(is_empty(&q));

    // Test `is_full()`
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    assert(is_full(&q));

    return 0;
}