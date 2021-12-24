#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) )

int quick_stage = 1;

void init_array(int A[], int n) {
    for (int i = 0; i < n; i++)
        A[i] = rand() % 100;
}

void print_pass(int A[], int n, int stage) {
    printf("pass %d : ", stage);
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    putchar('\n');
}

int partition(int A[], int left, int right) {
    int pivot, temp;
    int low, high;

    low = left;
    high = right + 1;
    pivot = A[left];
    do {
        do
            low++;
        while (A[low] < pivot);
        do
            high--;
        while (A[high] > pivot);
        if (low < high) SWAP(A[low], A[high], temp);
    } while (low < high);

    SWAP(A[left], A[high], temp);
    print_pass(A, 10, quick_stage++);
    return high;
}

void quick_sort(int A[], int left, int right) {
    if (left < right) {
        int q = partition(A, left, right);
        quick_sort(A, left, q - 1);
        quick_sort(A, q + 1, right);
    }
}

int sorted[10];
int merge_stage = 1;
void merge(int A[], int left, int mid, int right) {
    int i, j, k, l;
    i = left; j = mid + 1; k = left;

    while (i <= mid && j <= right) {
        if (A[i] <= A[j])
            sorted[k++] = A[i++];
        else
            sorted[k++] = A[j++];
    }
    while (i <= mid)
        sorted[k++] = A[i++];
    while (j <= right)
        sorted[k++] = A[j++];
    for (l = left; l <= right; l++)
        A[l] = sorted[l];
}
void merge_sort(int A[], int left, int right) {
    int mid;
    if (left < right) {
        mid = (left + right) / 2;
        merge_sort(A, left, mid);
        merge_sort(A, mid + 1, right);
        merge(A, left, mid, right);
        print_pass(A, 10, merge_stage++);
    }
}

int main(void) {
    int* array = (int*)malloc(sizeof(int) * 10);
    
    init_array(array, 10);
    puts("Quick sort");
    print_pass(array, 10, 0);
    quick_sort(array, 0, 9);
    print_pass(array, 10, quick_stage);

    init_array(array, 10);
    puts("Merge sort");
    print_pass(array, 10, 0);
    merge_sort(array, 0, 9);
    print_pass(array, 10, merge_stage);

    free(array);
    return 0;
}