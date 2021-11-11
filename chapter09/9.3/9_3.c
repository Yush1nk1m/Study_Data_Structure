#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
typedef struct {
    int key;
} element;
typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

// creation function
HeapType* create()
{
    return (HeapType*)malloc(sizeof(HeapType));
}

// initializing function
void init(HeapType* h)
{
    h->heap_size = 0;
}

// insert item to heap 'h' where the number of elements is 'heap_size'
// insertion function
void insert_max_heap(HeapType* h, element item)
{
    int i;
    i = ++(h->heap_size);

    // go up tree and compare with parent node
    while ((i != 1) && (item.key > h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;  // insert new node
}

// deletion function
element delete_max_heap(HeapType* h)
{
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;

    while (child <= h->heap_size) {
        // find the largest node between current node's child nodes
        if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key))
            child++;
        if (temp.key >= h->heap[child].key) break;
        // go down 1 level
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

int main(void)
{
    element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };
    element e4, e5, e6;
    HeapType* heap;

    heap = create();    // create a heap
    init(heap);         // initialize the heap

    // insertion
    insert_max_heap(heap, e1);
    insert_max_heap(heap, e2);
    insert_max_heap(heap, e3);

    // deletion
    e4 = delete_max_heap(heap);
    printf("< %d > ", e4.key);
    e5 = delete_max_heap(heap);
    printf("< %d > ", e5.key);
    e6 = delete_max_heap(heap);
    printf("< %d >\n", e6.key);

    free(heap);
    return 0;
}