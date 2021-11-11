#include <stdio.h>
#include <stdlib.h>
//
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
void insert_min_heap(HeapType* h, element item)
{
    int i;
    i = ++(h->heap_size);

    // go up tree and compare with parent node
    while ((i != 1) && (item.key < h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;  // insert new node
}

// deletion function
element delete_min_heap(HeapType* h)
{
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;

    while (child <= h->heap_size) {
        // find the largest node between current node's child nodes
        if ((child < h->heap_size) && (h->heap[child].key > h->heap[child + 1].key))
            child++;
        if (temp.key <= h->heap[child].key) break;
        // go down 1 level
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}
//

// sorting using heap(priority queue)
void heap_sort(element a[], int n)
{
    int i;
    HeapType* h;

    h = create();
    init(h);
    for (i = 0; i < n; i++) insert_min_heap(h, a[i]);
    for (i = 0; i < n; i++) a[i] = delete_min_heap(h);
    free(h);
}

#define SIZE 8
int main(void)
{
    element list[SIZE] = { 23, 56, 11, 9, 56, 99, 27, 34 };
    heap_sort(list, SIZE);
    for (int i = 0; i < SIZE; i++) printf("%d ", list[i].key);
    putchar('\n');
    return 0;
}