#include <stdio.h>
#include <math.h>

/* 01. 2���� ��ǥ �������� �ϳ��� ���� ��Ÿ���� ����ü Point�� �����Ͽ� ����.
typedef�� ����Ͽ��� ����ü Point�� �ϳ��� Ÿ������ �����Ѵ�. */

typedef struct point {
	double x;	// x ��ǥ
	double y;	// y ��ǥ
} Point;

/* 02. 01���� ������ ����ü ������ p1�� p2�� �����Ͽ� ����. */
/* 03. p1�� p2�� ���� (1, 2)�� (9, 8)�� �ʱ�ȭ�϶�. */
Point p1 = { 1, 2 };
Point p2 = { 9, 8 };

/* 04. ���� ��Ÿ���� �� ���� ����ü ������ �޾Ƽ� �� ������ �Ÿ��� ����ϴ�
�Լ� get_distance(Point p1, Point p2)�� �ۼ��Ͽ� ����. */
double get_distance(Point p1, Point p2) {
	double x_length_square = pow(p1.x - p2.x, 2);
	double y_length_square = pow(p1.y - p2.y, 2);
	return sqrt(x_length_square + y_length_square);
}

int main(void) {
	puts("p1 = (1, 2)");
	puts("p2 = (9, 8)\n");
	puts("p1�� p2 ������ �Ÿ��� ���մϴ�.");
	printf("get_distance(p1, p2) = %f\n", get_distance(p1, p2));

	return 0;
}