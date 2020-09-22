#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentTag {
	char name[20]; //���ڹ迭�� �� �̸�
	int age;
	double gpa; //��� ����
} student;

int main() {
	student* a; //�� �����ͷ�... --> �迭�̶�
	student b; // b�� �׳� ����ü
	a = (student*)malloc(sizeof(student));
	
	if (a == NULL) { //�Ҵ� ����
		fprintf(stderr, "�޸𸮰� �����ؼ� �Ҵ��� �� �����ϴ�.\n");
		exit(1); //���� �ڵ�
	}
	strcpy_s(a->name, "yoonseo"); // a�� name�� KIM ����(����)
	a->age = 21; 
	a->gpa = 3.5;
	printf("[ a-> ]\nname: %s\nage: %d\ngrade: %.1f\n\n", a->name, a->age, a->gpa); //�̸� ���� ���� ���
	printf("[ (*a). ]\nname: %s\nage: %d\ngrade: %.1f\n\n", (*a).name, (*a).age, (*a).gpa); //���� ���� �ǹ�!

	b = *a; // a�� ��(*a)�� b�� ����
	printf("[ b. ]\nname: %s\nage: %d\ngrade: %.1f\n", b.name, b.age, b.gpa); // b�� �Ϲ� ����ü�̹Ƿ� b.name (b->name ��� �Ұ�)
	
	free(a); //���� �Ҵ��� �ߴ� ����ü a ����
	return 0;
}

/*
 ������ ����ü�� ����� �����ϴ� ��� a->name
 a->name �� (*a).name ���ε� ǥ�� ����
*/