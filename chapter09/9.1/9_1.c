/* Definition of heap */
#define MAX_ELEMENT 200
typedef struct {
    int key;
} element;
typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

// insert item to heap where the number of elements is 'heap_size'
// insertion function
void insert_max_heap(HeapType* h, element item)
{
    int i;
    i = ++(h->heap_size);

    // go up and compare with parent node
    while ((i != 1) && (item.key > h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;  // insert new node
}