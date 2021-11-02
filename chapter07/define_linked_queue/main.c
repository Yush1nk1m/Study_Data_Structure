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