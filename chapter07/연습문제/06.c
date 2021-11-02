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

void reverse_print(DListNode* head)
{
    for (DListNode* p = head->llink; p != head; p = p->llink)
        printf("%d ", p->data);
    putchar('\n');
}

// doubly linked list test program
int main(void)
{
    DListNode* head = (DListNode*)malloc(sizeof(DListNode));
    init(head);
    
    DListNode* p = head;
    int n;
    printf("데이터의 개수를 입력하시오 : "); scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        element data;
        printf("노드 #%d의 데이터를 입력하시오 : ", i);
        scanf("%d", &data);
        dinsert(p, data);
        p = p->rlink;
    }
    printf("데이터를 역순으로 출력 : "); reverse_print(head);

    free(head);
    return 0;
}