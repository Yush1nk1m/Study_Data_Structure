#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix {
    int row;
    int col;
    int data;
    struct Matrix* link;
} Matrix;

typedef struct {
    int rows;
    int cols;
    Matrix* head;
} Information;

void print_matrix(Information* inf) {
    int i, j;
    Matrix* p = inf->head;
    for (i = 0; i < inf->rows; i++) {
        if (p->row != i) {
            for (j = 0; j < inf->cols; j++)
                printf("0 ");
            putchar('\n');
        }
        else {
            for (j = 0; j < inf->cols; j++) {
                if (p->row == i && p->col == j) {
                    printf("%d ", p->data);
                    p = p->link;
                }
                else printf("0 ");
            }
            putchar('\n');
        }
    }
}

int main(void) {
    Matrix head;
    head.row = 1; head.col = 1; head.data = 1;
    Matrix data2;
    data2.row = 2; data2.col = 2; data2.data = 2;
    head.link = &data2;
    Matrix data3;
    data3.row = 3; data3.col = 3; data3.data = 3;
    data2.link = &data3;

    Information inf;
    inf.rows = 5; inf.cols = 5; inf.head = &head;

    print_matrix(&inf);

    return 0;
}