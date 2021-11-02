#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* array;
    int size;
} SortedList;

void init(SortedList* list)
{
    list->size = 0;
}

void add(SortedList* list, int item)
{
    list->size++;
    if (list->size <= 1) {
        list->array = (int*)malloc(sizeof(int));
        list->array[0] = item;
    }
    else {
        list->array = (int*)realloc(list->array, list->size * sizeof(int));
        int i, j;
        for (i = 0; i < list->size - 1 && list->array[i] <= item; i++)
            ;
        for (j = list->size - 1; j > i; j--)
            list->array[j] = list->array[j - 1];
        list->array[j] = item;
    }
}

void display(SortedList* list)
{
    printf("list : ");
    for (int i = 0; i < list->size; i++)
        printf("%d ", list->array[i]);
}

int main(void) {
    SortedList list;
    init(&list);

    add(&list, 10);
    add(&list, 20);
    add(&list, 30);
    display(&list);

    return 0;
}