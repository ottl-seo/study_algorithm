#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentTag {
	char name[20]; //문자배열로 된 이름
	int age;
	double gpa; //평균 평점
} student;

int main() {
	student* a; //왜 포인터로... --> 배열이라서
	student b; // b는 그냥 구조체
	a = (student*)malloc(sizeof(student));
	
	if (a == NULL) { //할당 실패
		fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다.\n");
		exit(1); //종료 코드
	}
	strcpy_s(a->name, "yoonseo"); // a의 name에 KIM 저장(복사)
	a->age = 21; 
	a->gpa = 3.5;
	printf("[ a-> ]\nname: %s\nage: %d\ngrade: %.1f\n\n", a->name, a->age, a->gpa); //이름 나이 평점 출력
	printf("[ (*a). ]\nname: %s\nage: %d\ngrade: %.1f\n\n", (*a).name, (*a).age, (*a).gpa); //위와 같은 의미!

	b = *a; // a의 값(*a)을 b에 복사
	printf("[ b. ]\nname: %s\nage: %d\ngrade: %.1f\n", b.name, b.age, b.gpa); // b는 일반 구조체이므로 b.name (b->name 사용 불가)
	
	free(a); //동적 할당을 했던 구조체 a 해제
	return 0;
}

/*
 포인터 구조체의 멤버에 접근하는 방법 a->name
 a->name 은 (*a).name 으로도 표현 가능
*/