#include <stdio.h>
#include <stdlib.h>
#define STRING_SIZE 200
#define MAX_HEAP_SIZE 200

typedef struct {
    char task[STRING_SIZE];
    int priority;
} element;

typedef struct {
    element heap[MAX_HEAP_SIZE];
    int heap_size;
} HeapType;

void init(HeapType* h)
{
    h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item) {
    int i = ++(h->heap_size);
    while ((i != 1) && (item.priority > h->heap[i / 2].priority)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;
}

element delete_max_heap(HeapType* h) {
    element item, temp;
    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    int parent = 1, child = 2;
    while (child <= h->heap_size) {
        if ((child < h->heap_size) && (h->heap[child].priority < h->heap[child + 1].priority))
            child++;
        if (h->heap[child].priority < temp.priority) break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

int main(void) {
    HeapType heap;
    init(&heap);

    element e;
    char command;
    
    do {
        printf("insertion (i) | deletion (d) | quit (q) : ");
        scanf(" %c", &command);
        getchar();
        switch (command) {
            case 'i' :
                printf("Enter your task : "); scanf("%[^\n]", e.task);
                printf("Enter its priority : "); scanf("%d", &(e.priority));
                insert_max_heap(&heap, e);
                break;
            case 'd' :
                e = delete_max_heap(&heap);
                printf("the top priority is \"%s\".\n", e.task);
                break;
            case 'q' :
                break;
        }
    } while (command != 'q');
}