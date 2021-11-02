#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define of Stack
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
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
    StackType s;
    init_stack(&s);
    char* str = (char*)malloc(MAX_STACK_SIZE);
    printf("문자열을 입력하시오 : ");
    scanf("%s", str);
    push(&s, tolower(str[0]));
    int count = 1;
    for (int i = 1; i < strlen(str); i++) {
        if (peek(&s) == tolower(str[i])) {
            push(&s, tolower(str[i]));
            count++;
        }
        else {
            printf("%d%c", count, peek(&s));
            push(&s, tolower(str[i]));
            count = 1;
        }
    }
    printf("%d%c\n", count, peek(&s));

    free(str);
    return 0;
}