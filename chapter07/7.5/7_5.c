#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {  // doubly linked node type
    element data;
    struct DListNode* llink;
    struct DListNode* rlink;
} DListNode;

// insert new data on the right of before node
void dinsert(DListNode* before, element data)
{
    DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
    newnode->data = data;
    newnode->llink = before;
    newnode->rlink = before->rlink;
    newnode->rlink->llink = newnode;
    before->rlink = newnode;
}