/* ��ȣ�� �˻� �ڵ� ans */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef char element;
typedef struct stack {
	element data[MAX];
	int top; //�ְ� ������ �ε���
}StackType;

void init_stack(StackType* s) { //���� �ʱ�ȭ- ����ü �����͸� ���ڷ� ���޹���
	s->top = -1; // top �ʱ���´� -1
}
void error(const char* string) {
	fprintf(stderr, string); //���� �޽��� ���
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
bool parenth_check(char* X) { //���ڿ� X
	StackType* s = (StackType*)malloc(sizeof(StackType)); //���� ��ü ����
	char pop_ch, ch; //ch�� ���ڿ� �湮�ϸ� ���� �ϳ��ϳ�, pop_ch�� ���ÿ��� ������ ����
	init_stack(s);
	
	for (int i = 0; i < strlen(X); i++) {
		ch = X[i]; //���ڸ� �о�� - ���������� �迭�� �����ϳ��� ����
		switch (ch) {
		case '<': case '(': case '[': //���� ��ȣ
			push(s, ch);
			break;
		case '>': case ')': case ']': //�ݴ� ��ȣ
			if (is_empty(s)) { return false; }
			else {
				pop_ch = pop(s);
				if (((pop_ch == '<') && (ch != '>')) ||
					((pop_ch == '(') && (ch != ')')) ||
					((pop_ch == '[') && (ch != ']')))
					return false; //��ȣ�� �ȸ´���, && �� üũ, ������ false �����ʰ� ||�� �ѹ���
			}
			break;
		} //end of switch
	} //end of for
	if (!is_empty(s)) { return false; } //���ڿ� üũ �����µ� ���ÿ� ���� ��ȣ�� ���������� false
	return true; //�� üũ�� �� �ɸ��� �ʰ� �������� true
}

int main() {
	char str[100]; //���ڿ� �Է¹����� �迭�� !
	printf("Input expression\n");
	gets_s(str);
	if (parenth_check(str)) { printf("Correct\n"); } //����ϸ� correct
	else { printf("Incorrect"); } //false�� Incorr~

	return 0;
}