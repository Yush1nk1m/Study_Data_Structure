/* 10. 피보나치 수열을 효과적으로 계산하기 위하여 큐를 이용할 수 있다. 만일 피보나치 수열을 순환에
의하여 계산하게 되면 경우에 따라서는 많은 순환 함수의 호출에 의해 비효율적일 수 있다.
이를 개선하기 위하여 큐를 사용하는데 큐에는 처음에는 F(0)과 F(1)의 값이 들어가 있어 다음에 F(2)를
계산할 때 F(0)을 큐에서 제거한다. 그 다음에 계산된 F(b)를 다시 큐에 넣는다.
큐를 이용하여 피보나치 수열을 계산하는 프로그램을 작성하라. */

#include <stdio.h>
#include <stdlib.h>

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

int main(void) {
    QueueType q;
    init_queue(&q);
    enqueue(&q, 0);
    enqueue(&q, 1);
    int i = 2;
    
    int n;
    printf("몇 번째 피보나치 수를 구할까요? : "); scanf("%d", &n);
    if (n == 0) printf("0번째 피보나치 수는 0입니다.\n");
    else if (n == 1) printf("1번째 피보나치 수는 1입니다.\n");
    else {
        int f0, f1, f2;
        for (; i <= n; i++) {
            f0 = dequeue(&q);
            f1 = peek(&q);
            f2 = f0 + f1;
            enqueue(&q, f2);
        }
        printf("%d번째 피보나치 수는 %d입니다.\n", n, f2);
    }

    return 0;
}