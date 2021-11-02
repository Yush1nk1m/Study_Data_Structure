#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* array;
    int size;
} SortedList;

int is_empty(SortedList*);

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

void delete(SortedList* list, int item)
{
    if (!is_empty(list)) {
        int start, finish;
        for (start = 0; start < list->size; start++)
            if (list->array[start] == item) break;
        finish = start;
        while (list->array[finish] == item) finish++;
        if (start + 1 >= finish) {
            for (int i = start; i < list->size - 1; i++)
                list->array[i] = list->array[i + 1];
            list->size--;
            list->array = (int*)realloc(list->array, list->size * sizeof(int));
        }
        else { // start + 1 < finish
            int gap = finish - start;
            for (int i = start; i < list->size - gap; i++)
                list->array[i] = list->array[i + gap];
            list->size -= (gap);
            list->array = (int*)realloc(list->array, list->size * sizeof(int));
        }
    }
    else puts("list is empty.");
}

int is_in_list(SortedList* list, int item)
{
    int i;
    for (i = 0; i < list->size; i++)
        if (list->array[i] == item) return 1;
    else return 0;
}

int get_length(SortedList* list)
{
    return list->size;
}

int is_empty(SortedList* list)
{
    return (list->size == 0);
}

// 동적으로 공간을 확장하므로 is_full은 정의하지 않는다.

void clear(SortedList* list)
{
    list->size = 0;
    free(list->array);
}

void display(SortedList* list)
{
    printf("list : ");
    for (int i = 0; i < list->size; i++)
        printf("%d ", list->array[i]);
    putchar('\n');
}

int main(void) {
    SortedList list;
    init(&list);

    int option;
    do {
        int t;
        printf("Sorted List에 동작을 수행합니다. 종료하려면 -1을 입력하십시오.\n\
        (1 : add | 2 : delete | 3 : clear | 4 : get_length | 5 : is_in_list | 6 : is_empty | 7 : display) : ");
        scanf("%d", &option);
        switch (option) {
        case 1 :
            printf("Enter a item to add : ");
            scanf("%d", &t);
            add(&list, t);
            break;
        case 2 :
            printf("Enter a item to delete : ");
            scanf("%d", &t);
            delete(&list, t);
            break;
        case 3 :
            puts("clear Sorted List");
            printf("list's length : %d\n", get_length(&list));
            break;
        case 4 :
            printf("list's length : %d\n", get_length(&list));
            break;
        case 5 :
            printf("Enter a item to search : ");
            scanf("%d", &t);
            printf("%s", is_in_list(&list, t) ? "item is in list.\n" : "item is not in list.\n");
            break;
        case 6 :
            printf("%s", is_empty(&list) ? "list is empty" : "list is not empty");
            break;
        case 7 :
            display(&list);
            break;
        }
    } while (option != -1);
    puts("프로그램을 종료합니다.");

    return 0;
}