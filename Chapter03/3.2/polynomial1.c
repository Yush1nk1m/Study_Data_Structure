/* ��������. �� ���α׷��� �� ���׽��� �ְ����� ������ ���� ��ȣ�� �ٸ� ��츦
ó������ ���Ѵ�. �̰��� �ذ��ϴ� �ڵ带 �߰��غ���. */
#include <stdio.h>
#include <math.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MAX_DEGREE 101
typedef struct {			// ���׽� ����ü Ÿ�� ����
	int degree;				// ���׽��� ����
	float coef[MAX_DEGREE];	// ���׽��� ���
} polynomial;

// C = A + B ���⼭ A�� B�� ���׽��̴�. ����ü�� ��ȯ�ȴ�.
polynomial poly_add1(polynomial A, polynomial B)
{
	polynomial C;						// ��� ���׽�
	int Apos = 0, Bpos = 0, Cpos = 0;	// �迭 �ε��� ����
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree);	// ��� ���׽� ����
	
	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) {			// A�� > B��
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) {	// A�� == B��
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--; degree_b--;
		}
		else {								// B�� > A��
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

// ���Լ�
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