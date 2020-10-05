/* 5-2. ����ü ���� �迭 ��� ���� */
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef int element;
typedef struct StackType {
	element data[MAX]; //�迭�� ��� (element Ÿ��)
	int top; //top���� ����� ������. top�� �ְ� ������ �ε���
}StackType;

void init_stack(StackType* s) { //���� �ʱ�ȭ- ����ü �����͸� ���ڷ� ���޹���
	s->top = -1; // top �ʱ���´� -1
}
void error(const char* string) {
	fprintf(stderr, string); //���� �޽��� ���
}
bool is_full(StackType* s);
bool is_empty(StackType* s);
element pop(StackType* s);
void push(StackType* s, element e);

int main() {
	int input;
	int count=0;
	StackType s; //����ü ���� s ����
	init_stack(&s); //����ü �ʱ�ȭ!!!
	
	printf("Input Integer to push stack: ");
	scanf_s("%d", &input);
	while (input != 0) {
		push(&s, input); //���ÿ� �ִ´�
		count++;

		printf("Input Integer to push stack: ");
		scanf_s("%d", &input);
	}
	printf("\n< Stack >\n");
	for (int i = 0; i < count; i++) {
		printf("%d\n", pop(&s));
	}
	
	return 0;
}

bool is_full(StackType* s) {
	if (s->top == MAX) { return true; } 
	else { return false; }
}
bool is_empty(StackType* s) {
	if (s->top == -1) { return true; }
	else { return false; }
}
element pop(StackType* s) {
	if (is_empty(s)) {
		error("Stack Empty");
		exit(1);
	}
	else {
		return (s->data[s->top--]); //top�� ���߿� --, data�� �迭�̹Ƿ� []
	}
}
void push(StackType* s, element value) {
	if (is_full(s)) {
		error("Stack Overflow");
		return;
	}
	else {
		s->data[++(s->top)] = value; // ++����, s->data�� top ���� value ����.
	}
}

/*
* ���ڷ� ������(*s) ������, �Ű����� �������� ������ "�ּҰ�"���� ������
	-- *s �� �����ϸ�, s�� �ּҰ�/ *s�� �� �̹Ƿ�, (s)�� ������ ��
	-- s �� �����ϸ�, s�� ��/ &s�� �ּҰ� �̹Ƿ�, (&s)�� ������ ��
* 
*/