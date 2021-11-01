#include <stdio.h>
#include <stdlib.h>
/* 08. 원형 큐에 존재하는 요소의 개수를 반환하는 연산 get_count를 추가하여 보라.
        C언어를 이용하여 구현하여 보라.*/
// ===== 원형 큐 코드 시작 =====
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {    // 큐 타입
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

// 오류 함수
void error(char* message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 초기화 함수
void init_queue(QueueType* q)
{
    q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType* q)
{
    return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType* q)
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 원형 큐 출력 함수
void queue_print(QueueType* q)
{
    printf("QUEUE(front = %d | rear = %d) = ", q->front, q->rear);
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
void enqueue(QueueType* q, element item)
{
    if (is_full(q))
        error("큐가 포화 상태입니다.");
    q->rear = (q->rear + 1) % (MAX_QUEUE_SIZE);
    q->data[q->rear] = item;
}

// 삭제 함수
element dequeue(QueueType* q)
{
    if (is_empty(q))
        error("큐가 공백 상태입니다.");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

// 피크 함수
element peek(QueueType* q)
{
    if (is_empty(q))
        error("큐가 공백 상태입니다.");
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
// ===== 원형 큐 코드 끝 =====

int get_count(QueueType* q)
{
    if (q->front <= q->rear) return (q->rear - q->front);
    else return (q->rear + MAX_QUEUE_SIZE - q->front);
}

int main(void) {
    QueueType q;
    init_queue(&q);
    int task;
    do {
        do {
        printf("동작을 입력해 주십시오. (enqueue = 0, dequeue = 1) : "); scanf("%d", &task);
        } while (task != 0 && task != 1);
        if (task == 0) {
            element data;
            printf("정수 데이터 입력 : "); scanf("%d", &data);
            enqueue(&q, data);
            queue_print(&q);
        }
        else {
            element data = dequeue(&q);
            printf("큐에서 데이터 %d을(를) 추출했습니다.\n남은 데이터 개수 : %d\n", data, get_count(&q));
        }
    } while (!is_empty(&q));

    return 0;
}