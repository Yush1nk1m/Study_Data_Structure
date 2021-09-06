#include <stdio.h>
#include <math.h>

/* 01. 2차원 좌표 공간에서 하나의 점을 나타내는 구조체 Point를 정의하여 보라.
typedef도 사용하여서 구조체 Point를 하나의 타입으로 정의한다. */

typedef struct point {
	double x;	// x 좌표
	double y;	// y 좌표
} Point;

/* 02. 01에서 정의한 구조체 변수인 p1과 p2를 정의하여 보라. */
/* 03. p1과 p2를 각각 (1, 2)와 (9, 8)로 초기화하라. */
Point p1 = { 1, 2 };
Point p2 = { 9, 8 };

/* 04. 점을 나타내는 두 개의 구조체 변수를 받아서 점 사이의 거리를 계산하는
함수 get_distance(Point p1, Point p2)를 작성하여 보자. */
double get_distance(Point p1, Point p2) {
	double x_length_square = pow(p1.x - p2.x, 2);
	double y_length_square = pow(p1.y - p2.y, 2);
	return sqrt(x_length_square + y_length_square);
}

int main(void) {
	puts("p1 = (1, 2)");
	puts("p2 = (9, 8)\n");
	puts("p1과 p2 사이의 거리를 구합니다.");
	printf("get_distance(p1, p2) = %f\n", get_distance(p1, p2));

	return 0;
}