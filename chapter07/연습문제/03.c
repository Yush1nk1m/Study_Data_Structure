#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {   // Node type
    element data;
    struct ListNode* link;
} ListNode;

// print list's elements
void print_list(ListNode* head)
{
    ListNode* p;

    if (head == NULL) return;
    p = head->link;
    do {
        printf("%d -> ", p->data);
        p = p->link;
    } while (p != head);
    printf("%d -> ...\n", p->data); // print last node
}

ListNode* insert_first(ListNode* head, element data)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;    // (1)
        head->link = node;          // (2)
    }
    return head;    // return changed head pointer.
}

ListNode* insert_last(ListNode* head, element data)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;    // (1)
        head->link = node;          // (2)
        head = node;                // (3)
    }
    return head;    // return changed head pointer.
}

// search data in circular linked list L and return that node
ListNode* search(ListNode* head, element data)
{
    ListNode* p;
    for (p = head; p->link != head; p = p->link)
        if (p->data == data) return p;
    if (p->data == data) return p;
    else return NULL;
}

// circular linked list test program
int main(void)
{
    ListNode* head = NULL;

    // list = 10 -> 20 -> 30 -> 40 -> ...
    head = insert_last(head, 20);   // assign returned head pointer by insert_last function into head
    print_list(head);
    head = insert_last(head, 30);
    print_list(head);
    head = insert_last(head, 40);
    print_list(head);
    head = insert_first(head, 10);
    print_list(head);

    ListNode* res = search(head, 40);
    printf("search result : %d\n", res->data);
    
    return 0;
}