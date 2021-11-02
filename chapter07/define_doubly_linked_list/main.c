typedef int element;
typedef struct DListNode {  // doubly linked node type
    element data;
    struct DListNode* llink;
    struct DListNode* rlink;
} DListNode;