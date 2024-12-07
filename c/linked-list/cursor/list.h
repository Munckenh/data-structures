#ifndef CURSOR_LINKED_LIST_H
#define CURSOR_LINKED_LIST_H

typedef struct {
    int data;
    int next;
} Node;

typedef struct {
    Node* heap;
    int available;
    int size;
} VirtualHeap;

void initialize_heap(VirtualHeap*, int);
int allocate(VirtualHeap*);
void deallocate(VirtualHeap*, int);
void insert_at_beginning(VirtualHeap*, int*, int);
void insert_at_index(VirtualHeap*, int*, int, int);
void insert_at_end(VirtualHeap*, int*, int);
void insert_sorted(VirtualHeap*, int*, int);
void delete_by_index(VirtualHeap*, int*, int);
void delete_by_data(VirtualHeap*, int*, int);
void display(VirtualHeap, int);

#endif