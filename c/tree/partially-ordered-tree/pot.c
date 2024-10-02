#include <stdlib.h>
#include "pot.h"

void initialize(struct tree* tree, int size) {
    tree->size = size;
    tree->array = (int*)malloc(sizeof(int) * size);
    tree->last_index = 0;
}

int get_parent(int child_index) {
    return (child_index - 1) / 2;
}

int get_left_child(int parent_index) {
    return 2 * parent_index + 1;
}

int get_right_child(int parent_index) {
    return 2 * parent_index + 2;
}

void push(struct tree* tree, int data) {
    // TODO: Implement code
}

int pop(struct tree* tree) {
    // TODO: Implement code
}
