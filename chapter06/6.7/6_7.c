// test every code in directory 6.1 ~ 6.6
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {   // Node type
    element data;
    struct ListNode* link;
} ListNode;

// Error Handling Function
void error(char* message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListNode* insert_first(ListNode* head, element value)
{
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));  // (1)
    p->data = value;                                    // (2)
    p->link = head;     // copying head pointer's value // (3)
    head = p;           // change head pointer          // (4)
    return head;        // return changed head pointer  // (5)
}

// insert new node after pre node
ListNode* insert(ListNode* head, ListNode* pre, element value)
{
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));  // (1)
    p->data = value;                                    // (2)
    p->link = pre->link;                                // (3)
    pre->link = p;                                      // (4)
    return head;                                        // (5)
}

ListNode* delete_first(ListNode* head)
{
    ListNode* removed;
    if (head == NULL) return NULL;
    removed = head;         // (1)
    head = removed->link;   // (2)
    free(removed);          // (3)
    return head;            // (4)
}

// delete pre-linked node
ListNode* delete(ListNode* head, ListNode* pre)
{
    ListNode* removed;
    removed = pre->link;        // (1)
    pre->link = removed->link;  // (2)
    free(removed);              // (3)
    return head;                // (4)
}

void print_list(ListNode* head)
{
    for (ListNode* p = head; p != NULL; p = p->link)
        printf("%d -> ", p->data);
    puts("NULL");
}

// test program
int main(void)
{
    ListNode* head = NULL;

    for (int i = 0; i < 5; i++) {
        head = insert_first(head, i);   // assign returned head pointer into head
        print_list(head);
    }
    for (int i = 0; i < 5; i++) {
        head = delete_first(head);
        print_list(head);
    }
    return 0;
}