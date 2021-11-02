#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct information {
    char name[10];
    int age;
    float height;
    struct information* link;
} information;

information* insert_node(information** head, char name[10], int age, float height)
{
    information* new = (information*)calloc(1, sizeof(information));
    strcpy(new->name, name);
    new->age = age;
    new->height = height;
    if (*head == NULL) *head = new;
    else {
        information* p = *head;
        while (p->link != NULL)
            p = p->link;
        p->link = new;
    }
    return *head;
}

void print_information(information* head)
{
    for (information* p = head; p != NULL; p = p->link)
        printf("Name : %s\nAge : %d\nHeight : %.1f\n\n", p->name, p->age, p->height);
}

int main(void) {
    information* head = NULL;
    information* p;
    int n;
    printf("사람 수를 입력하시오 : "); scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("%d번째 사람의 정보를 입력 받습니다.\n", i + 1);
        char name[10];
        int age;
        float height;
        printf("이름을 입력하시오 : "); scanf("%s", name);
        printf("나이를 입력하시오 : "); scanf("%d", &age);
        printf("키를 입력하시오 : "); scanf("%f", &height);
        insert_node(&head, name, age, height);
    }
    print_information(head);

    return 0;
}