#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ===== 원형 큐 코드 시작 =====
#define MAX_QUEUE_SIZE 5
typedef struct {
    int id;
    int arrival_time;
    int service_time;
} element;
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

// 도전문제. 은행의 행원이 2명이라면 소스를 어떻게 수정하여야 하는가?

int main(void)
{
    int minutes = 60;
    int total_wait = 0;
    int total_customers = 0;
    int clerk1_service_time = 0, clerk2_service_time = 0;
    int clerk1_service_customer, clerk2_service_customer;
    QueueType queue;
    init_queue(&queue);

    srand(time(NULL));
    for (int clock = 0; clock < minutes; clock++) {
        printf("현재 시각 = %d\n", clock);
        if ((rand() % 10) < 3) {
            element customer;
            customer.id = total_customers++;
            customer.arrival_time = clock;
            customer.service_time = rand() % 3 + 1;
            enqueue(&queue, customer);
            printf("고객 %d이 %d분에 들어옵니다. 업무 처리 시간 = %d분\n",
            customer.id, customer.arrival_time, customer.service_time);
        }
        if (clerk1_service_time > 0) {
            printf("은행원 1이 고객 %d의 업무를 처리 중입니다.\n", clerk1_service_customer);
            clerk1_service_time--;
        }
        else {
            if (!is_empty(&queue)) {
                element customer = dequeue(&queue);
                clerk1_service_customer = customer.id;
                clerk1_service_time = customer.service_time;
                printf("고객 %d의 업무가 %d분에 시작됩니다. 대기 시간은 %d분이었습니다. (담당자 : 은행원 1)\n",
                customer.id, clock, clock - customer.arrival_time);
                total_wait += clock - customer.arrival_time;
            }
        }
        
        
        
        
        if (clerk2_service_time > 0) {
            printf("은행원 2가 고객 %d의 업무를 처리 중입니다.\n", clerk2_service_customer);
            clerk2_service_time--;
        }
        else {
            if (!is_empty(&queue)) {
                element customer = dequeue(&queue);
                clerk2_service_customer = customer.id;
                clerk2_service_time = customer.service_time;
                printf("고객 %d의 업무가 %d분에 시작됩니다. 대기 시간은 %d분이었습니다. (담당자 : 은행원 2)\n",
                customer.id, clock, clock - customer.arrival_time);
                total_wait += clock - customer.arrival_time; 
            }
        }
    }
    printf("전체 대기 시간 = %d분\n", total_wait);
    return 0;
}