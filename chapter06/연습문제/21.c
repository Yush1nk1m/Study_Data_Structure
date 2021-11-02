#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ListNode { // node type
    int coef;
    int expon;
    struct ListNode* link;
} ListNode;

// header of linked list
typedef struct ListType { // list header type
    int size;
    ListNode* head;
    ListNode* tail;
} ListType;

// error function
void error(char* message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// creating list header function
ListType* create()
{
    ListType* plist = (ListType*)malloc(sizeof(ListType));
    plist->size = 0;
    plist->head = plist->tail = NULL;
    return plist;
}

// plist is pointer which points linked list's header, coef is coefficient, expon is exponent.
void insert_last(ListType* plist, int coef, int expon)
{
    ListNode* temp =
        (ListNode*)malloc(sizeof(ListNode));
    if (temp == NULL) error("memory allocation error");
    temp->coef = coef;
    temp->expon = expon;
    temp->link = NULL;
    if (plist->tail == NULL) {
        plist->head = plist->tail = temp;
    }
    else {
        plist->tail->link = temp;
        plist->tail = temp;
    }
    plist->size++;
}

// list3 = list1 + list2
void poly_add(ListType* plist1, ListType* plist2, ListType* plist3)
{
    ListNode* a = plist1->head;
    ListNode* b = plist2->head;
    int sum;

    while (a && b) {
        if (a->expon == b->expon) { // degrees of a == degrees of b
            sum = a->coef + b->coef;
            if (sum != 0) insert_last(plist3, sum, a->expon);
            a = a->link; b = b->link;
        }
        else if (a->expon > b->expon) { // degrees of a > degrees of b
            insert_last(plist3, a->coef, a->expon);
            a = a->link;
        }
        else {
            insert_last(plist3, b->coef, b->expon);
            b = b->link;
        }
    }

    // insert left terms
    while (a) {
        insert_last(plist3, a->coef, a->expon);
        a = a->link;
    }
    while (b) {
        insert_last(plist3, b->coef, b->expon);
        b = b->link;
    }
}

void poly_print(ListType* plist)
{
    ListNode* p = plist->head;

    printf("polynomial = ");
    while (p->link) {
        printf("%d^%d + ", p->coef, p->expon);
        p = p->link;
    }
    printf("%d^%d\n", p->coef, p->expon);
}

int poly_eval(ListType* plist, int value)
{
    ListNode* p = plist->head;
    int total = 0;
    while (p != NULL) {
        total += p->coef * pow(value, p->expon);
        p = p->link;
    }
    return total;
}

int main(void)
{
    ListType *poly = create();
    
    int n;
    printf("항의 개수 : "); scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int coef;
        int expon;
        printf("%d번째 항의 계수 : ", i + 1); scanf("%d", &coef);
        printf("%d번째 항의 차수 : ", i + 1); scanf("%d", &expon);
        insert_last(poly, coef, expon);
    }

    printf("x의 값 : "); scanf("%d", &n);
    int res = poly_eval(poly, n);
    printf("다항식의 미지수에 %d를 대입하면 %d의 결과값이 나온다.\n", n, res);

    return 0;
}