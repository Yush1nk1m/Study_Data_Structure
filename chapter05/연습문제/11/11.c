/* 11. 회문(palindrome)이란 앞뒤 어느 쪽에서 읽어도 같은 말.구.문 등을 의미한다.
예를 들어 "eye", "madam", "radar" 등이다. 여기서 물론 구두점이나 스페이스, 대소문자 등은 무시하여야 한다.
덱을 이용하여 주어진 문자열이 회문인지 아닌지를 결정하는 프로그램을 작성하라. */

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10
typedef char element;
typedef struct {    // 큐 타입
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} DequeType;

// 오류 함수
void error(char* message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 초기화
void init_deque(DequeType* q)
{
    q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(DequeType* q)
{
    return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(DequeType* q)
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 원형 큐 출력 함수
void deque_print(DequeType* q)
{
    printf("DEQUE(front = %d | rear = %d) = ", q->front, q->rear);
    if (!is_empty(q)) {
        int i = q->front;
        do {
            i = (i + 1) % (MAX_QUEUE_SIZE);
            printf("%d | ", q->data[i]);
            if (i == q->rear)
                break;
        } while (i != q->front);
    }
    putchar('\n');
}

// 삽입 함수
void add_rear(DequeType* q, element item)
{
    if (is_full(q))
        error("큐가 포화 상태입니다.");
    q->rear = (q->rear + 1) % (MAX_QUEUE_SIZE);
    q->data[q->rear] = item;
}

// 삭제 함수
element delete_front(DequeType* q)
{
    if (is_empty(q))
        error("큐가 공백 상태입니다.");
    q->front = (q->front + 1) % (MAX_QUEUE_SIZE);
    return q->data[q->front];
}

// 피크 함수
element get_front(DequeType* q)
{
    if (is_empty(q))
        error("큐가 공백 상태입니다.");
    return q->data[(q->front + 1) % (MAX_QUEUE_SIZE)];
}

element add_front(DequeType* q, element item)
{
    if (is_full(q))
        error("큐가 포화 상태입니다.");
    q->data[q->front] = item;
    q->front = (q->front - 1 + MAX_QUEUE_SIZE) % (MAX_QUEUE_SIZE);
}

element delete_rear(DequeType* q)
{
    int prev = q->rear;
    if (is_empty(q))
        error("큐가 공백 상태입니다.");
    q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % (MAX_QUEUE_SIZE);
    return q->data[prev];
}

element get_rear(DequeType* q)
{
    if (is_empty(q))
        error("큐가 공백 상태입니다.");
    return q->data[q->rear];
}

int main(void) {
    DequeType q;
    init_deque(&q);
    char c;
    printf("문자열을 입력하시오 : ");
    c = getchar();
    while (c != '\n') {
        add_front(&q, c);
        c = getchar();
    }

    while (!is_empty(&q)) {
        if (get_front(&q) == get_rear(&q)) {
            delete_front(&q);
            if (!is_empty(&q)) {
                delete_rear(&q);
            }
        }
        else break;
    }

    printf("입력한 문자열은 회문%s", is_empty(&q) ? "입니다." : "이 아닙니다.");
    return 0;   
}