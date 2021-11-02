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

int get_size(StackType s) {
    StackType tmp;
    init_stack(&tmp);
    int count = 0;
    while (!is_empty(&s)) {
        push(&tmp, pop(&s));
        count++;
    }
    while (!is_empty(&tmp)) {
        push(&s, pop(&tmp));
    }
    return count;
}

int main(void) {
    StackType s;
    int size;
    init_stack(&s);
    printf("스택에 넣을 요소의 개수를 입력해 주십시오 : "); scanf("%d", &size);
    printf("요소를 입력해 주십시오 : ");
    int tmp;
    for (int i = 0; i < size; i++) {
        scanf("%d", &tmp);
        push(&s, tmp);
    }
    printf("get_size(&s) = %d\n", get_size(s));

    return 0;
}