#include <stdio.h>
#include <stdlib.h>

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

int main(void)
{
    ListType *list1, *list2, *list3;

    // create linked list header
    list1 = create();
    list2 = create();
    list3 = create();

    // create polynomial1
    insert_last(list1, 3, 12);
    insert_last(list1, 2, 8);
    insert_last(list1, 1, 0);

    // create polynomial2
    insert_last(list2, 8, 12);
    insert_last(list2, -3, 10);
    insert_last(list2, 10, 6);

    poly_print(list1);
    poly_print(list2);

    // polynomial3 = polynomial1 + polynomial2
    poly_add(list1, list2, list3);
    poly_print(list3);

    free(list1); free(list2); free(list3);

    return 0;
}