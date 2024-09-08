#include <stdlib.h>
#include <assert.h>
#include "set.h"

void populate(struct node** a, struct node** b) {
    *a = create_node(0);
    (*a)->next = create_node(1);
    (*a)->next->next = create_node(2);
    (*a)->next->next->next = create_node(4);
    (*a)->next->next->next->next = create_node(7);
    *b = create_node(2);
    (*b)->next = create_node(3);
    (*b)->next->next = create_node(4);
    (*b)->next->next->next = create_node(5);
    (*b)->next->next->next->next = create_node(6);
    (*b)->next->next->next->next->next = create_node(8);
    (*b)->next->next->next->next->next->next = create_node(9);
}

void test() {
    // Test `create_node()`
    struct node* node = create_node(10);
    assert(node->data == 10);
    assert(node->next == NULL);

    // Make two sets
    // a = { 0, 1, 2, 4, 7 }
    // b = { 2, 3, 4, 5, 6, 8, 9 }
    struct node* a, * b;
    populate(&a, &b);

    // Test `cardinality()`
    assert(cardinality(a) == 5);
    assert(cardinality(b) == 7);

    // Test `contains()`
    assert(contains(a, 7));
    assert(!contains(b, 7));

    // Test `get_union()`
    struct node* c = get_union(a, b);
    assert(cardinality(c) == 10);

    // Test `get_intersection()`
    struct node* d = get_intersection(a, b);
    assert(cardinality(d) == 2);
    assert(contains(d, 2));
    assert(contains(d, 4));
}

int main() {
    test();
    return 0;
}