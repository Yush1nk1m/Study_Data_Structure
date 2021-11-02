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

// remove 'removed' node
void ddelete(DListNode* head, DListNode* removed)
{
    if (removed == head) return;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}