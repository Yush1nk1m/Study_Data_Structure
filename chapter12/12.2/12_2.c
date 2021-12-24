#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) )

int list[MAX_SIZE];
int n;

void selection_sort(int list[], int n)
{
    int i, j, least, temp;
    for (i = 0; i < n - 2; i++) {
        least = i;
        for (j = i; j < n - 1; j++)
            if (list[j] < list[least]) least = j;
        SWAP(list[i], list[least], temp);
    }
}

int main(void)
{
    int i;
    n = MAX_SIZE;
    srand(time(NULL));
    for (i = 0; i < n; i++)         // create random numbers and print them
        list[i] = rand() % 100;     // random number range : 0 ~ 99
    
    selection_sort(list, n);        // call selection sort
    for(i = 0; i < n; i++)
        printf("%d ", list[i]);
    putchar('\n');
    return 0;
}