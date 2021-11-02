// define
typedef int element;

typedef struct ListNode {   // define Node type as a struct
    element data;
    struct ListNode* link;
} ListNode;


// declaration of NULL list
ListNode* head = NULL;

// declaration of Node
head = (ListNode*)malloc(sizeof(ListNode));

head->data = 10;
head->link = NULL;

// linking of Node
ListNode* p;
p = (ListNode*)malloc(sizeof(ListNode));
p->data = 20;
p->link = NULL;

head->link = p;