/* 12. 연결 리스트에서 특정한 데이터 값을 갖는 노드의 개수를 계산하는 함수를 작성하라. */

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

ListNode* insert_next(ListNode* head, element value)
{
    if (head == NULL) {
        head->data = value;
        return head;
    }
    else {
        ListNode* p = head;
        while (p->link != NULL)
            p = p->link;
        ListNode* next = (ListNode*)calloc(1, sizeof(ListNode));
        next->data = value;
        p->link = next;
        return head;
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

// delete pre-linked node
ListNode* delete(ListNode* head, ListNode* pre)
{
    ListNode* removed;
    removed = pre->link;        // (1)
    pre->link = removed->link;  // (2)
    free(removed);              // (3)
    return head;                // (4)
}

int sum_list(ListNode* head)
{
    int sum = 0;
    for (ListNode* p = head; p != NULL; p = p->link)
        sum += p->data;
    return sum;
}

void print_list(ListNode* head)
{
    for (ListNode* p = head; p != NULL; p = p->link)
        printf("%d -> ", p->data);
    puts("NULL");
}

int search_count(ListNode* head, element value)
{
    ListNode* p = head;
    int count = 0;
    while (p != NULL) {
        if (p->data == value) count++;
        p = p->link;
    }
    return count;
}

int main(void) {
    ListNode* head = (ListNode*)calloc(1, sizeof(ListNode));
    ListNode* p = head;
    int n;
    element value;

    printf("노드의 개수 : "); scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("노드 #%d 데이터 : ", i);
        element dat; scanf("%d", &dat);
        head = insert_next(head, dat);
    }
    print_list(head);
    printf("탐색할 값을 입력하시오 : "); scanf("%d", &value);
    printf("%d는 연결 리스트에서 %d번 나타납니다.\n", value, search_count(head, value));

    free(head);
    return 0;
}