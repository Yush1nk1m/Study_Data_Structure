/* 09. 2개의 스택을 사용하여 큐를 구현해보자. 입력이 들어오면 스택 #1에 넣는다.
출력 요청이 들어오면 스택 #2에서 요소를 꺼낸다. 스택 #2가 비어있을 때는 스택 #1의
모든 요소를 꺼내서 스택 #2에 넣는다. 프로그램으로 작성해보자. */

#include <stdio.h>
#include <stdlib.h>

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
// 피크 함수
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
    StackType enqueue_stack, dequeue_stack;
    init_stack(&enqueue_stack); init_stack(&dequeue_stack);

    puts("스택을 이용해 큐 구현하기");
    
    int task;
    
    do {
        do {
        printf("동작을 입력해 주십시오. (Enqueue : 0, Dequeue : 1) : "); scanf("%d", &task);
        } while (task != 0 && task != 1);
        
        if (task == 0) {
            element data;
            printf("정수 데이터 입력 : "); scanf("%d", &data);
            printf("데이터 %d을(를) enqueue합니다.\n", data);
            push(&enqueue_stack, data);
        }
        else {
            while (!is_empty(&enqueue_stack)) push(&dequeue_stack, pop(&enqueue_stack));
            printf("데이터 %d을(를) dequeue합니다.\n", pop(&dequeue_stack));
            while (!is_empty(&dequeue_stack)) push(&enqueue_stack, pop(&dequeue_stack));
        }
    } while (!is_empty(&enqueue_stack));

    return 0;
}