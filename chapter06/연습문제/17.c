#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

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

ListNode* insert_next(ListNode** head, element value)
{
    if (*head == NULL) {
        ListNode* new = (ListNode*)calloc(1, sizeof(ListNode));
        new->data = value;
        *head = new;
        return *head;
    }
    else {
        ListNode* p = (*head);
        while (p->link != NULL)
            p = p->link;
        ListNode* new = (ListNode*)calloc(1, sizeof(ListNode));
        new->data = value;
        p->link = new;
        return *head;
    }
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

ListNode* search_delete(ListNode* head, element value)
{
    if (head == NULL) return NULL;
    while (head->data == value) {
        ListNode* removed;
        removed = head;
        head = removed->link;
        free(removed);
    }
    if (head->link == NULL) return NULL;

    ListNode* fp = head;
    ListNode* p = head->link;
    while (p != NULL) {
        if (p->data == value) {
            p = p->link;
            fp->link = p;
        }
        else {
            fp = fp->link;
            p = p->link;
        }
    }
    return head;
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

int count_list(ListNode* head)
{
    int count = 0;
    for (ListNode* p = head; p != NULL; p = p->link)
        count++;
    return count;
}

int sum_list(ListNode* head)
{
    int total = 0;
    for (ListNode* p = head; p != NULL; p = p->link)
        total += p->data;
    return total;
}

int search_count(ListNode* head, element value)
{
    int count = 0;
    for (ListNode* p = head; p != NULL; p = p->link) {
        if (p->data == value) count++;
    }
    return count;
}

int find_max(ListNode* head)
{
    int max = head->data;
    for (ListNode* p = head->link; p != NULL; p = p->link)
        if (max < p->data) max = p->data;
    return max;
}

int find_min(ListNode* head)
{
    int min = head->data;
    for (ListNode* p = head->link; p != NULL; p = p->link)
        if (min > p->data) min = p->data;
    return min;
}

ListNode* delete_odd(ListNode* head)
{
    for (ListNode* p = head; p != NULL; p = p->link)
        p->link = p->link->link;
    return head;
}

ListNode* alternate(ListNode* headA, ListNode* headB)
{
    ListNode* headC = NULL;
    ListNode *pa = headA, *pb = headB;
    for (; pa != NULL && pb != NULL; pa = pa->link, pb = pb->link) {
        headC = insert_next(&headC, pa->data);
        insert_next(&headC, pb->data);
    }
    while (pa != NULL) {
        insert_next(&headC, pa->data);
        pa = pa->link;
    }
    while (pb != NULL) {
        insert_next(&headC, pb->data);
        pb = pb->link;
    }
    
    return headC;
}

void print_list(ListNode* head)
{
    for (ListNode* p = head; p != NULL; p = p->link)
        printf("%d -> ", p->data);
    puts("NULL");
}

int main(void) {
    ListNode* headA = NULL;
    ListNode* headB = NULL;
    int n1, n2;
    element tmp;
    do {
        printf("A 노드의 개수 : "); scanf("%d", &n1);
    } while (n1 <= 0);
    
    for (int i = 0; i < n1; i++) {
        printf("노드 A의 #%d 데이터 : ", i + 1);
        scanf("%d", &tmp);
        headA = insert_next(&headA, tmp);
    }
    printf("Linked list A : "); print_list(headA);

    do {
        printf("B 노드의 개수 : "); scanf("%d", &n2);
    } while (n2 <= 0);
    
    for (int i = 0; i < n2; i++) {
        printf("노드 B의 #%d 데이터 : ", i + 1);
        scanf("%d", &tmp);
        headB = insert_next(&headB, tmp);
    }
    printf("Linked list B : "); print_list(headB);

    ListNode* headC = alternate(headA, headB);
    printf("alternated linked list : "); print_list(headC);

    return 0;
}