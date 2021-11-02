#include <stdio.h>
#include <stdlib.h>

typedef int element;    // element type
typedef struct QueueNode {  // Queue's node type
    element data;
    struct QueueNode* link;
} QueueNode;

typedef struct {    // Implement of Queue ADT
    QueueNode *front, *rear;
} LinkedQueueType;

// initializing queue function
void init(LinkedQueueType* q)
{
    q->front = q->rear = NULL;
}

// empty status detection function
int is_empty(LinkedQueueType* q)
{
    return (q->front == NULL);
}

// full status detection function
int is_full(LinkedQueueType* q)
{
    return 0;
}

// insertion function
void enqueue(LinkedQueueType* q, element data)
{
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->data = data;  // save data
    temp->link = NULL;  // link field = NULL
    if (is_empty(q)) {
        q->front = temp;
        q->rear = temp;
    }
    else {
        q->rear->link = temp;
        q->rear = temp;
    }
}

// deletion function
element dequeue(LinkedQueueType* q)
{
    QueueNode* temp = q->front;
    element data;
    if (is_empty(q)) {
        fprintf(stderr, "Queue is empty.\n");
        exit(1);
    }
    else {
        data = temp->data;          // pop data
        q->front = q->front->link;  // make front point next node
        if (q->front == NULL)       // empty status
            q->rear = NULL;
        free(temp);                 // release dynamic memory
        return data;                // return data
    }
}

void print_queue(LinkedQueueType* q)
{
    QueueNode* p;
    for (p = q->front; p != NULL; p = p->link)
        printf("%d -> ", p->data);
    puts("NULL");
}

// linked queue test function
int main(void)
{
    LinkedQueueType queue;

    init(&queue);   // initialize queue

    enqueue(&queue, 1); print_queue(&queue);
    enqueue(&queue, 2); print_queue(&queue);
    enqueue(&queue, 3); print_queue(&queue);
    dequeue(&queue); print_queue(&queue);
    dequeue(&queue); print_queue(&queue);
    dequeue(&queue); print_queue(&queue);
    return 0;
}