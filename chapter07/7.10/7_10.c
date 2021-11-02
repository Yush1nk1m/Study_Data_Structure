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