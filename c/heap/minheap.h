#ifndef MIN_HEAP_H
#define MIN_HEAP_H
#include <stdbool.h>

typedef struct {
    int* array;
    int size;
    int capacity;
} Heap;

Heap* create_heap(int capacity);
void swap(int* a, int* b);
bool is_max_heap(Heap heap);
void insert(Heap* heap, int value);
int extract(Heap* heap);
void heapify(Heap* heap, int index);

#endif