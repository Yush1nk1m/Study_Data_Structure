#include <stdio.h>

typedef struct studentTag {
	char name[10];	// 문자 배열로 된 이름
	int age;		// 나이를 나타내는 정수값
	double gpa;		// 평균 평점을 나타내는 실수값
} student;

int main(void)
{
	student a = { "kim", 20, 4.3 };
	student b = { "park", 21, 4.2 };
	printf("student a\nname : %s\nage : %d\ngpa : %.1f\n", a.name, a.age, a.gpa);
	printf("student b\nname : %s\nage : %d\ngpa : %.1f\n", b.name, b.age, b.gpa);
	return 0;
}