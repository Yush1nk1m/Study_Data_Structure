/* 13. 단순 연결 리스트에서의 탐색 함수를 참고하여 특정한 데이터 값을 갖는 노드를 삭제하는 함수를 작성하라. */

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
    if (head->link == NULL) {
        puts("insert_next find head->link as NULL");
        head->data = value;
        return head;
    }
    else {
        puts("insert_next find head->link as !NULL");
        ListNode* p = head;
        while (p->link != NULL)
            p = p->link;
        ListNode* next = (ListNode*)malloc(sizeof(ListNode));
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

ListNode* particular_delete(ListNode* head, element value)
{
    while (head->data == value)
        head = head->link;
    ListNode* p = head->link;
    ListNode* fp = head;
    do {
        if (p->data == value) {
            fp->link = p->link;
            p = p->link;
        }
        fp = fp->link;
        p = p->link;
    } while (p != NULL);
    return head;
}

int main(void) {
    ListNode* head = (ListNode*)calloc(1, sizeof(head));
    ListNode* p = head;
    int n;

    printf("노드의 개수 : "); scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("노드 #%d 데이터 : ", i);
        element dat; scanf("%d", &dat);
        insert(head, p, dat);
        p = p->link;
    }
    printf("입력 받은 연결 리스트 : "); print_list(head);

    element value;
    printf("연결 리스트에서 삭제할 값을 입력하시오 : "); scanf("%d", &value);
    head = particular_delete(head, value);
    printf("수정된 연결 리스트 : "); print_list(head);

    free(head);
    return 0;
}