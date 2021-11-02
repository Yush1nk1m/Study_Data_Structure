// define
typedef int element;

typedef struct ListNode {   // define Node type as a struct
    element data;
    struct ListNode* link;
} ListNode;

// insert new node between pre node and its next node
ListNode* insert(ListNode* head, ListNode* pre, element value)
{
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));  // (1)
    p->data = value;                                    // (2)
    p->link = pre->link;                                // (3)
    pre->link = p;                                      // (4)
    return head;                                        // (5)
}