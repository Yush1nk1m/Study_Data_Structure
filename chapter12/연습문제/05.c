#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) )

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

void selection_sort(int A[], int n) {
    int min, temp;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j <= n - 1; j++)
            if (A[j] < A[min]) min = j;
        SWAP(A[i], A[min], temp);
        print_pass(A, n, i + 1);
    }
}

void insertion_sort(int A[], int n) {
    int key, temp;
    int i, j;
    for (i = 1; i < n; i++) {
        key = A[i];
        for (j = i - 1; j >= 0 && key < A[j]; j--)
            A[j + 1] = A[j];
        A[j + 1] = key;
        print_pass(A, n, i);
    }
}

void bubble_sort(int A[], int n) {
    int temp;
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++)
            if (A[j] > A[j + 1])
                SWAP(A[j], A[j + 1], temp);
        print_pass(A, n, n - i);
    }
}

void inc_insertion_list(int A[], int first, int last, int gap) {
    int i, j, key;
    for (i = first + gap; i <= last; i += gap) {
        key = A[i];
        for (j = i - gap; j >= first && key < A[j]; j -= gap)
            A[j + gap] = A[j];
        A[j + gap] = key;
    }
}

void shell_sort(int A[], int n) {
    int i, gap;
    int stage = 1;
    for (gap = n / 2; gap > 0; gap /= 2) {
        if ((gap % 2) == 0) gap++;
        for (i = 0; i < gap; i++)
            inc_insertion_list(A, i, n - 1, gap);
        print_pass(A, n, stage++);
    }
}

int main(void) {
    int* array = (int*)malloc(sizeof(int) * 10);
    srand(time(NULL));
    init_array(array, 10);
    puts("(1) Selection sort");
    print_pass(array, 10, 0);
    selection_sort(array, 10);

    init_array(array, 10);
    puts("(2) Insertion sort");
    print_pass(array, 10, 0);
    insertion_sort(array, 10);

    init_array(array, 10);
    puts("(3) Bubble sort");
    print_pass(array, 10, 0);
    bubble_sort(array, 10);

    init_array(array, 10);
    puts("(4) Shell sort");
    print_pass(array, 10, 0);
    shell_sort(array, 10);

    free(array);
    return 0;
}