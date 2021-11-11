/* LPT program */
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
    int id;
    int avail;
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

// insert item into heap 'h' where the number of elements is 'heap_size'
// insertion function
void insert_min_heap(HeapType* h, element item)
{
    int i;
    i = ++(h->heap_size);

    // go up tree and compare with parent node
    while ((i != 1) && (item.avail < h->heap[i / 2].avail)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item; // insert new node
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
        // find the smallest child node
        if ((child < h->heap_size) && (h->heap[child].avail) > (h->heap[child + 1].avail))
            child++;
        if (temp.avail < h->heap[child].avail) break;
        // go down 1 level
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

#define JOBS 7
#define MACHINES 3

int main(void)
{
    int jobs[JOBS] = { 8, 7, 6, 5, 3, 2, 1 };    // suppose that jobs are sorted
    element m = { 0, 0 };
    HeapType* h;
    h = create();
    init(h);

    // avail value means machines' usable time
    for (int i = 0; i < MACHINES; i++) {
        m.id = i + 1;
        m.avail = 0;
        insert_min_heap(h, m);
    }
    // pop out machines from min heap and allocate jobs and re-insert into min_heap
    for (int i = 0; i < JOBS; i++) {
        m = delete_min_heap(h);
        printf("allocate JOB %d from time = %d to time = %d into machine number %d.\n",
            i, m.avail, m.avail + jobs[i] - 1, m.id);
        m.avail += jobs[i];
        insert_min_heap(h, m);
    }
    return 0;
}