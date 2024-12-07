#include <stdlib.h>
#include <stdio.h>
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
    if (address == -1)
        return;
    vh->heap[address].data = data;
    vh->heap[address].next = *head;
    *head = address;
}

void insert_at_index(VirtualHeap* vh, int* head, int data, int index) {
    int address = allocate(vh);
    if (address == -1)
        return;
    vh->heap[address].data = data;
    int* current;
    int i;
    for (i = 0, current = head; i < index && *current != -1; current = &vh->heap[*current].next, i++);
    vh->heap[address].next = *current;
    *current = address;
}

void insert_at_end(VirtualHeap* vh, int* head, int data) {
    int address = allocate(vh);
    if (address == -1)
        return;
    vh->heap[address].data = data;
    vh->heap[address].next = -1;
    int* current;
    for (current = head; *current != -1; current = &vh->heap[*current].next);
    *current = address;
}

void insert_sorted(VirtualHeap* vh, int* head, int data) {
    int address = allocate(vh);
    if (address == -1)
        return;
    vh->heap[address].data = data;
    int* current;
    for (current = head; *current != -1 && vh->heap[*current].data < data; current = &vh->heap[*current].next);
    vh->heap[address].next = *current;
    *current = address;
}

void delete_by_index(VirtualHeap* vh, int* head, int index) {
    // TODO: Implement function
}

void delete_by_data(VirtualHeap* vh, int* head, int data) {
    // TODO: Implement function
}

void display(VirtualHeap vh, int head) {
    for (int current = head; current != -1; current = vh.heap[current].next) {
        printf("%d ", vh.heap[current].data);
    }
}