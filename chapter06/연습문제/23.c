#include <stdio.h>
#include <stdlib.h>

typedef struct SortedList {
    int data;
    struct SortedList* link;
} SortedList;

int is_empty(SortedList**);

SortedList* add(SortedList** head, int item)
{
    if (*head == NULL) {
        SortedList* new = (SortedList*)malloc(sizeof(SortedList));
        new->data = item; new->link = NULL;
        *head = new;
        return *head;
    }
    else {
        SortedList* p = (*head)->link;
        SortedList* fp = (*head);
        SortedList* new = (SortedList*)malloc(sizeof(SortedList));
        new->data = item; new->link = NULL;
        for (; p != NULL; p = p->link, fp = fp->link)
            if (p->data == item) {
                fp->link = new;
                new->link = p;
                return *head;
            }
        fp->link = new;
        return *head;
    }
}

SortedList* delete(SortedList** head, int item)
{
    if (!is_empty(head)) {
        SortedList* p = (*head)->link;
        SortedList* fp = *head;
        while (p != NULL) {
            if (p->data == item) {
                SortedList* removed = p;
                fp->link = removed->link;
                p = removed->link;
                free(removed);
            }
            else {
                p = p->link;
                fp = fp->link;
            }
        }
        if ((*head)->data == item) {
            SortedList* removed = *head;
            *head = removed->link;
            free(removed);
        }
        return *head;
    }
    else return NULL;
}

void clear(SortedList** head)
{
    while (*head != NULL) {
        SortedList* removed = *head;
        *head = removed->link;
        free(removed);
    }
}

int is_in_list(SortedList* head, int item)
{
    for (SortedList* p = head; p != NULL; p = p->link)
        if (p->data == item) return 1;
    else return 0;
}

int get_length(SortedList* head)
{
    int length = 0;
    for (SortedList* p = head; p != NULL; p = p->link)
        length++;
    return length;
}

int is_empty(SortedList** head)
{
    return (*head == NULL);
}

// 동적으로 공간을 확장하므로 is_full은 정의하지 않는다.

void display(SortedList* head) {
    SortedList* p;
    for (p = head; p->link != NULL; p = p->link)
        printf("%d -> ", p->data);
    printf("%d\n", p->data);
}

int main(void) {
    SortedList* head = NULL;
    head = add(&head, 2);
    head = add(&head, 2);
    head = add(&head, 2);
    head = add(&head, 2);
    head = add(&head, 3);
    display(head);
    delete(&head, 2);
    display(head);

    return 0;
}