#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define of Stack
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct {
    element data[(MAX_STACK_SIZE)];
    int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s)
{
    s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s)
{
    return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s)
{
    return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입 함수
void push(StackType* s, element item)
{
    if (is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else s->data[++(s->top)] = item;
}
// 삭제 함수
element pop(StackType* s)
{
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

element peek(StackType* s)
{
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[(s->top)];
}
// Define of Stack

int main(void) {
    char str1[MAX_STACK_SIZE] = { 0 };
    char str2[MAX_STACK_SIZE] = { 0 };

    printf("문자열을 입력하시오 : ");
    StackType s1, s2, s3;
    init_stack(&s1);
    init_stack(&s2);
    init_stack(&s3);

    char c = getchar();
    while (c != '\n') {
        if ('A' <= c && c <= 'z') {
            push(&s1, tolower(c));
            push(&s2, tolower(c));
        }
        c = getchar();
    }

    while (!is_empty(&s2)) {
        push(&s3, pop(&s2));
    }

    int i = 0;
    while (!is_empty(&s1)) {
        str1[i] = pop(&s1);
        str2[i] = pop(&s3);
        i++;
    }

    if (strcmp(str1, str2) == 0) puts("회문입니다.");
    else puts("회문이 아닙니다.");

    return 0;
}