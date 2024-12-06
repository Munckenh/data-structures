#include <stdio.h>
#include <limits.h>
#include "minheap.h"

Heap* create_heap(int capacity) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->array = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

bool is_max_heap(Heap heap) {
    bool result = true;

    // Start from the parent of the last leaf node
    for (int i = (heap.size - 2) / 2; i >= 0 && result; i--) {
        // A left child should always exist if you start from the parent of the last leaf node
        // See whether current node is greater than the left child
        if (heap.array[i] > heap.array[i * 2 + 1])
            result = false;

        // See whether the right child is valid
        // See whether current node is greater than the right child
        int right_child = i * 2 + 2;
        if (right_child < heap.size && heap.array[i] > heap.array[right_child])
            result = false;
    }
    return result;
}

void insert(Heap* heap, int value) {
    if (heap->size < heap->capacity) {
        int i = heap->size++;
        heap->array[i] = value;

        // If the min heap property is violated, keep swapping values until the current node is the root
        while (i != 0 && heap->array[i] < heap->array[(i - 1) / 2]) {
            swap(&heap->array[i], &heap->array[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
    printf("Heap overflow\n");
}

int extract(Heap* heap) {
    if (heap->size == 0)
        return INT_MAX;
    if (heap->size == 1)
        return heap->array[--heap->size];

    // Store the root node to return it later
    int root = heap->array[0];

    // Swap the values of the root node and the last leaf
    heap->array[0] = heap->array[heap->size-- - 1];

    heapify(heap, 0);
    return root;
}

// Recursive version of heapify
void heapify(Heap* heap, int index) {
    int smallest = index;
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;

    // If left child exists, and left child is smaller than current smallest node
    if (left_child < heap->size && heap->array[left_child] < heap->array[smallest])
        smallest = left_child;

    // If right child exists, and left child is smaller than current smallest node
    if (right_child < heap->size && heap->array[right_child] < heap->array[smallest])
        smallest = right_child;

    // If the index is still the smallest, then min heap property is satisfied
    // Otherwise, swap the values of the current index and the smallest child
    // And then, recur
    if (smallest != index) {
        swap(&heap->array[index], &heap->array[smallest]);
        heapify(heap, smallest);
    }
}

// Non-recursive version of heapify
void heapify_v2(Heap* heap, int index) {
    int smallest, left_child, right_child;
    while (true) {
        smallest = index;
        left_child = 2 * index + 1;
        right_child = 2 * index + 2;

        if (left_child < heap->size && heap->array[left_child] < heap->array[smallest])
            smallest = left_child;
        if (right_child < heap->size && heap->array[right_child] < heap->array[smallest])
            smallest = right_child;
        if (smallest == index)
            break;

        swap(&heap->array[index], &heap->array[smallest]);
        index = smallest;
    }
}