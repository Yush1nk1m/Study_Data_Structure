// define
typedef int element;

typedef struct ListNode {   // define Node type as a struct
    element data;
    struct ListNode* link;
} ListNode;

// printing list algorithm
void print_list(ListNode* head)
{
    for (ListNode* p = head; p != NULL; p = p->link)
        printf("%d -> ", p->data);
    puts("NULL");
}