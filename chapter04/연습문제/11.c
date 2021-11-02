#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    printf("수식 : ");
    scanf("%s", str);
    int t = 1;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(') {
            printf("%d ", t);
            push(&s, t++);
        }
        else if (str[i] == ')') printf("%d ", pop(&s));
        else continue;
    }

    free(str);
    return 0;
}