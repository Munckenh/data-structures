#include <stdlib.h>
#include "list.h"

void initialize_heap(VirtualHeap* vh, int size) {
    vh->heap = (Node*)malloc(sizeof(Node) * size);
    vh->available = size - 1;
    vh->size = size;
    for (int i = 0; i < size; i++) {
        vh->heap[i].next = i - 1;
    }
}

int allocate(VirtualHeap* vh) {
    int address = vh->available;
    if (address != -1) {
        vh->available = vh->heap[address].next;
    }
    return address;
}

void deallocate(VirtualHeap* vh, int index) {
    if (index >= 0 && index < vh->size) {
        vh->heap[index].next = vh->available;
        vh->available = index;
    }
}

void insert_at_beginning(VirtualHeap* vh, int* head, int data) {
    int address = allocate(vh);
    if (address != -1) {
        vh->heap[address].data = data;
        vh->heap[address].next = *head;
        *head = address;
    }
}

void insert_at_index(VirtualHeap* vh, int* head, int data, int index) {
    // TODO: Implement function
}

void insert_at_end(VirtualHeap* vh, int* head, int data) {
    // TODO: Implement function
}

void insert_sorted(VirtualHeap* vh, int* head, int data) {
    // TODO: Implement function
}

void delete_by_index(VirtualHeap* vh, int* head, int index) {
    // TODO: Implement function
}

void delete_by_data(VirtualHeap* vh, int* head, int data) {
    // TODO: Implement function
}


int main() {
    int head = -1;
    VirtualHeap vh;
    initialize_heap(&vh, 10);
    return 0;
}