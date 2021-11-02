#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define of Stack
#define MAX_STACK_SIZE 100

typedef char element;
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
    char* str = (char*)malloc(MAX_STACK_SIZE);
    
    printf("정수를 입력하시오 : ");
    scanf("%s", str);
    push(&s, str[strlen(str) - 1]);
    printf("출력 : ");
    for (int i = strlen(str) - 2; i > 0; i--) {
        if (peek(&s) != str[i]) {
            push(&s, str[i]);
        }
    }
    if (peek(&s) != str[0]) push(&s, str[0]);
    while (!is_empty(&s)) printf("%c", pop(&s));
    putchar('\n');

    free(str);
    return 0;
}