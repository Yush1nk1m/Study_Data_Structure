#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_TERMS 101
typedef struct {
	float coef;
	int expon;
} polynomial;
polynomial terms[MAX_TERMS] = { {8, 3}, {7, 1}, {1, 0}, {10, 3}, {3, 2}, {1, 0} };
int avail = 6;

// 두 개의 정수를 비교
char compare(int a, int b)
{
	if (a > b) return '>';
	else if (a == b) return '=';
	else return '<';
}

// 새로운 항을 다항식에 추가한다.
void attach(float coef, int expon)
{
	if (avail > MAX_TERMS) {
		fprintf(stderr, "항의 개수가 너무 많음\n");
		exit(1);
	}
	terms[avail].coef = coef;
	terms[avail].expon = expon;
	avail++;
}

void poly_read(char* filename) {
	FILE* f = fopen(filename, "r");
	double tempcoef[MAX_TERMS];
	int tempexpon[MAX_TERMS];
	int ci = 0, ei = 0;
	do {
		fscanf(f, "%lf", &tempcoef[ci]);
		fgetc(f); fgetc(f);
		fscanf(f, "%d", &tempexpon[ei]);
		fgetc(f); fgetc(f);
		printf("읽은 coef : %f, 읽은 expon : %d\n", tempcoef[ci], tempexpon[ei]);
		ci++; ei++;
	} while (fgetc(f) != EOF);
	int i;
	for (i = 0; i < ci - 1; i++)
		printf("%3.1lfx^%d + ", tempcoef[i], tempexpon[i]);
	printf("%3.1lfx^%d\n", tempcoef[i], tempexpon[i]);
	fclose(f);
}

// C = A + B
void poly_add2(int As, int Ae, int Bs, int Be, int* Cs, int* Ce)
{
	float tempcoef;
	*Cs = avail;
	while (As <= Ae && Bs <= Be)
		switch (compare(terms[As].expon, terms[Bs].expon)) {
		case '>' :		// A의 차수 > B의 차수
			attach(terms[As].coef, terms[As].expon);
			As++;		break;
		case '=' :		// A의 차수 == B의 차수
			tempcoef = terms[As].coef + terms[Bs].coef;
			if (tempcoef)	// 0 == false, !0 == true
				attach(tempcoef, terms[As].expon);
			As++; Bs++;	break;
		case '<' :		// A의 차수 < B의 차수
			attach(terms[Bs].coef, terms[Bs].expon);
			Bs++;		break;
		}
	// A의 나머지 항들을 이동함
	for (; As <= Ae; As++)
		attach(terms[As].coef, terms[As].expon);
	// B의 나머지 항들을 이동함
	for (; Bs <= Be; Bs++)
		attach(terms[Bs].coef, terms[Bs].expon);
	*Ce = avail - 1;
}
void print_poly(int s, int e)
{
	for (int i = s; i < e; i++)
		printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
	printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);
}

double poly_eval(int x) {	// Cs, Ce가 이미 정해져 있다고 가정한다.
	double total = 0;
	int Cs, Ce;
	printf("Cs : "); scanf("%d", &Cs);
	printf("Ce : "); scanf("%d", &Ce);
	while (Cs <= Ce) {
		total += terms[Cs].coef * pow(x, terms[Cs].expon);
		Cs++;
	}
	return total;
}
//
int main(void)
{
	//char filename[20];
	int As = 0, Ae = 2, Bs = 3, Be = 5, Cs, Ce;
	poly_add2(As, Ae, Bs, Be, &Cs, &Ce);
	print_poly(As, Ae);
	print_poly(Bs, Be);
	printf("-------------------------------------------\n");
	print_poly(Cs, Ce);
	printf("poly_eval(2) : %3.1f\n", poly_eval(2));
	
	//printf("파일 이름 : "); scanf("%s", filename);
	//puts("다항식을 읽어 들입니다.");
	//poly_read(filename);
	
	return 0;
}