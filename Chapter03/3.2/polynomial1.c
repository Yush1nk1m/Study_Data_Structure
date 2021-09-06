/* 도전문제. 이 프로그램은 두 다항식의 최고차항 절댓값이 같고 부호는 다른 경우를
처리하지 못한다. 이것을 해결하는 코드를 추가해보자. */
#include <stdio.h>
#include <math.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MAX_DEGREE 101
typedef struct {			// 다항식 구조체 타입 선언
	int degree;				// 다항식의 차수
	float coef[MAX_DEGREE];	// 다항식의 계수
} polynomial;

// C = A + B 여기서 A와 B는 다항식이다. 구조체가 반환된다.
polynomial poly_add1(polynomial A, polynomial B)
{
	polynomial C;						// 결과 다항식
	int Apos = 0, Bpos = 0, Cpos = 0;	// 배열 인덱스 변수
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree);	// 결과 다항식 차수
	
	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) {			// A항 > B항
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) {	// A항 == B항
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--; degree_b--;
		}
		else {								// B항 > A항
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	int find_zero = 0;
	while (C.coef[find_zero] == 0) {
		C.degree--;
		find_zero++;
	}
	for (int i = find_zero; i <= find_zero + C.degree; i++)
		C.coef[i - find_zero] = C.coef[i];
	return C;
}

void print_poly(polynomial p)
{
	for (int i = p.degree; i > 0; i--)
		printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	printf("%3.1f\n", p.coef[p.degree]);
}

double poly_eval(int x) {
	double total = 0;
	polynomial c;
	printf("degree : "); scanf("%d", &c.degree);
	for (int i = 0; i <= c.degree; i++) {
		printf("coef[%d] : ", i); scanf("%f", &c.coef[i]);
	}
	for (int i = 0; i <= c.degree; i++)
		total += c.coef[i] * pow(x, c.degree - i);
	return total;
}

// 주함수
int main(void)
{
	polynomial a = { 3, {1, 0, 2, 3} };
	polynomial b = { 3, {3, 0, 4, -1} };
	polynomial c;

	print_poly(a);
	print_poly(b);
	c = poly_add1(a, b);
	printf("------------------------------------------------------\n");
	print_poly(c);
	double res = poly_eval(2);
	printf("poly_eval(2) : %f\n", res);
	return 0;
}