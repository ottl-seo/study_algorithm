/* week5. ����ü�� ���� �Ҵ� ���
	 - ����ü member�� �����Ҵ� �ϱ�
	 ����ü ����� �����ͷ� ����, malloc���� �����޸𸮸� �Ҵ� �޾� ���� ���� */
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct StackType {
	element *data; // ������ �������� �Ҵ��ϰ� �̸� data�� ����Ű���� ��
	int capacity; //���� �����Ҵ� ���� �޸� ũ�� (++, -- ���� ��ü������)
	int top; //�ְ� ������ �ε���
}StackType;

void init_stack(StackType* s) { //���� �ʱ�ȭ �Լ�
	s->capacity = 1;
	s->top = -1; //top �ʱⰪ�� -1
	s->data = (element*)malloc(s->capacity * sizeof(element)); //element�ϳ��� ũ�� * ������ ũ��
}
void error(const char* message) {
	fprintf(stderr, message); //���� �޽��� ���
}
bool is_full(StackType* s) {
	return (s->top >= s->capacity - 1); //top�� �޸�ũ�⺸�� Ŀ���� �޸� ��ȭ ����
}
bool is_empty(StackType* s) {
	return (s->top == - 1); //�� ������ ��� (top�� �ʱ���� -1�� ��)
}
element pop(StackType* s) { //��������
	if (is_empty(s)) {
		error("Stack empty");
		exit(1);
	}
	else { return (s->data[(s->top)--]); } // data[] top �� ���� �����ϰ�, top �� �ٿ��ֱ�
}
void push(StackType* s, element e) {
	if (is_full(s)) { //ũ�⸦ ���� �Ҵ��ϹǷ� ���� �����÷ο� �߻���Ű�� �ʰ� �÷��ֱ�
		s->capacity *= 2;
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
			//���� ������ �����ϸ鼭 ���� �޸𸮸� �ٽ� �Ҵ�-- realloc(���� ������, size) 
	}
	s->data[++(s->top)] = e; //top ���� �� ���Ұ� ����
}

int main() {
	StackType s;
	init_stack(&s);

	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	printf("\n<Stack>\n%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));

	free(s.data); //s.data�� init()�Լ� ������ ���� �Ҵ� �������Ƿ� Ǯ���ش�
	return 0;
}
/* 
* �迭 �����ͺ��� data �� ���Ұ��� �����ϴ� ���? -- �迭ó�� data[] �� �����ϸ� �ȴ�. �³� �̰͵� �����

* (*s) �� �����ϰ� �����Ҵ� �����ָ� �ȵǳ�? -- X �ȵ�. �ʱ�ȭ ���� �ʾҴٰ� ��. 
* 
* �Լ��� ���� �ڷ����� (StackType *s)�� �������־����Ƿ�, s�� ���� �� &s �� ������ �ּҰ� �����ֱ� !
	// StackType* s �̸�, "�ּҰ�"���� �����϶�� �ǹ���

+++ �����Բ� ����
- element* data �� ��ȯ�ϴµ� pop�Լ��� ���ϰ��� element* �� �ƴ϶� elemnt�� ������ ����? */