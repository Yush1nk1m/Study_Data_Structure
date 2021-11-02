#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {  // doubly linked node type
    element data;
    struct DListNode* llink;
    struct DListNode* rlink;
} DListNode;

// initialize doubly linked list
void init(DListNode* phead)
{
    phead->llink = phead;
    phead->rlink = phead;
}

// print doubly linked list's nodes
void print_dlist(DListNode* phead)
{
    DListNode* p;
    for (p = phead->rlink; p != phead; p = p->rlink)
        printf("<- | %d | -> ", p->data);
    putchar('\n');
}

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

// doubly linked list test program
int main(void)
{
    DListNode* head = (DListNode*)malloc(sizeof(DListNode));
    init(head);
    puts("추가 단계");
    for (int i = 0; i < 5; i++) {
        // inserting on the right of head node
        dinsert(head, i);
        print_dlist(head);
    }
    puts("\n삭제 단계");
    for (int i = 0; i < 5; i++) {
        print_dlist(head);
        ddelete(head, head->rlink);
    }
    free(head);

    return 0;
}