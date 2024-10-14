#include <assert.h>
#include "bst.h"

void populate(struct node** root) {
    insert(root, 40);
    insert(root, 30);
    insert(root, 50);
    insert(root, 25);
    insert(root, 35);
    insert(root, 45);
    insert(root, 60);
}

void test() {
    struct node* root;
    initialize(&root);
    populate(&root);
    assert(root->key == 40);
    assert(search(root, 30));
    assert(search(root, 50));
    assert(search(root, 25));
    assert(search(root, 35));
    assert(search(root, 45));
    assert(search(root, 60));
    assert(search(root, 60));
    assert(!search(root, 55));
    assert(!search(root, -1));
    assert(pop_maximum(&root) == 60);
    assert(pop_minimum(&root) == 25);
}

int main() {
    test();
    return 0;
}