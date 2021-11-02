/* 도전문제. 추상 자료형 "리스트"의 연산 중에서 insert_first(list, item) 연산을
구현하여 테스트하라. */

/* 도전문제. ArrayListType을 malloc() 함수를 이용하여 동적으로 생성하고 여기에
10, 20, 30을 추가하는 코드를 작성하고 테스트하라. */

#include <stdio.h>
#include <stdlib.h>

typedef int element;    // 항목의 정의
typedef struct {
    element* array;   // 배열 정의
    int size;                       // 현재 리스트에 저장된 항목들의 개수
    int max_size;   // 리스트의 최대 크기
} ArrayListType;

// 오류 처리 함수
void error(char* message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 리스트 초기화 함수
void init(ArrayListType* L, int s)
{
    L->array = (element*)malloc(s * sizeof(int));
    L->size = 0;
    L->max_size = s;
}

void del(ArrayListType* L)
{
    free(L->array);
}

// 리스트가 비어 있으면 1을 반환
// 그렇지 않으면 0을 반환
int is_empty(ArrayListType* L)
{
    return L->size == 0;
}

// 리스트가 가득 차 있으면 1을 반환
// 그렇지 않으면 0을 반환
int is_full(ArrayListType* L)
{
    return L->size == L->max_size;
}

element get_entry(ArrayListType* L, int pos)
{
    if (pos < 0 || pos >= L->size)
        error("index error");
    return L->array[pos];
}

// 리스트 출력
void print_list(ArrayListType* L)
{
    int i;
    for (i = 0; i < L->size - 1; i++)
        printf("%d->", L->array[i]);
    printf("%d\n", L->array[i]);
}

void insert_first(ArrayListType* L, element item)
{
    if (L->size >= L->max_size)
        error("list overflow");
    for (int i = L->size - 1; i >= 0; i--)
        L->array[i + 1] = L->array[i];
    L->size++;
    L->array[0] = item;
}

void insert_last(ArrayListType* L, element item)
{
    if (L->size >= L->max_size)
        error("list overflow");
    L->array[L->size++] = item;
}

void insert(ArrayListType* L, int pos, element item)
{
    if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
        for (int i = (L->size - 1); i >= pos; i--)
            L->array[i + 1] = L->array[i];
        L->array[pos] = item;
        L->size++;
    }
}

void clear(ArrayListType* L)
{
    while (!is_empty(&L)) {
        L->array[L->size - 1];
        L->size--;
    }
}

void replace(ArrayListType* L, int pos, element item)
{
    L->array[pos] = item;
}

int get_length(ArrayListType* L)
{
    return L->size;
}

element delete(ArrayListType* L, int pos)
{
    element item;

    if (pos < 0 || pos >= L->size)
        error("index error");
    item = L->array[pos];
    for (int i = pos; i < (L->size - 1); i++)
        L->array[i] = L->array[i + 1];
    L->size--;
    return item;
}

int main(void)
{
    ArrayListType L;
    init(&L, 100);
    for (int i = 1; i <= 3; i++)
        insert_first(&L, i * 10);
        print_list(&L);
    
    del(&L);
    return 0;
}