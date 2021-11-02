// define
typedef int element;

typedef struct ListNode {   // define Node type as a struct
    element data;
    struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, int value)
{
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));  // (1)
    p->data = value;                                    // (2)
    p->link = head;     // 헤드 포인터의 값을 복사      // (3)
    head = p;           // 헤드 포인터 변경             // (4)
    return head;        // 변경된 헤드 포인터 반환      // (5)
}