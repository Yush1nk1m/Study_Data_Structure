// define
typedef int element;

typedef struct ListNode {   // define Node type as a struct
    element data;
    struct ListNode* link;
} ListNode;

// singly linked list's delete function
ListNode* delete_first(ListNode* head)
{
    ListNode* removed;
    if (head == NULL) return NULL;
    removed = head;         // (1)
    head = removed->link;   // (2)
    free(removed);          // (3)
    return head;            // (4)
}