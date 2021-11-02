// define
typedef int element;

typedef struct ListNode {   // define Node type as a struct
    element data;
    struct ListNode* link;
} ListNode;

// delete pre-linked node's next node
ListNode* delete(ListNode* head, ListNode* pre)
{
    ListNode* removed;
    removed = pre->link;        // (1)
    pre->link = removed->link;  // (2)
    free(removed);              // (3)
    return head;                // (4)
}