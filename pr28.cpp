/* ������ ����: ��ȣ�� �˻� */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef char element; //element�� char Ÿ��
typedef struct stack {
	element *ch; //���� �迭. ���⿡ �״´�. init()���� �����Ҵ� �Ұ�
	int capacity; //�迭 ũ��(���ڿ��� ����)
	int top; //�ְ� ������ �ε���
}stack;

void init(stack* s) { //���� �ʱ�ȭ �Լ�
	s->top = -1;
	s->capacity = 1;
	s->ch = (element*)malloc(s->capacity * sizeof(element));
}
void error(const char* message) {
	fprintf(stderr, message); //���� �޽��� ��� �Լ�
}
bool is_full(stack* s) {
	if (s->top == s->capacity - 1) { return true; }
	else { return false; }
}
bool is_empty(stack *s){
	if (s->top == -1) { return true; }
	else { return false; }
}
element pop(stack* s) { //pop �Լ�
	if (is_full(s)) {
		s->capacity *= 2; //2��� �÷��ְ�
		s->ch = (element*)realloc(s->ch, s->capacity * sizeof(element)); //�ٽ� �Ҵ����ش�
	}
	else { return (s->ch[s->top--]); }
}
void push(stack* s, element item) {
	if (is_empty(s)) {
		error("Stack empty");
		exit(1);
	}
	else {
		s->ch[++(s->top)] = item; //item�� ���� top�� �־��ش�
	}
}
int main(){
	char input[MAX]; //�Է¹��� �� �����Ҵ縻�� �迭[MAX]�� ����...?!
	int i = 0; int length = 0; //for���� ���
	bool is_correct = true;
	stack* mystack = (stack*)malloc(sizeof(stack)); //mystack ����

	printf("Input expression\n");
	scanf_s("%s", input);

	length = strlen(input);
	for (int i = 0; i > length; i++) {
		switch (input[i])
		{
		case '<': case '{': case '[':
			push(mystack, input[i]);
			break;
		case '>':
			if (pop(mystack) != '<') { is_correct = false; }
			break;
		case '}':
			if (pop(mystack) == '{') { break; }
			else {
				is_correct = false;
				break;
			}
		case ']':
			if (pop(mystack) == '[') { break; }
			else {
				is_correct = false;
				break;
			}
		default:
			break; //�̿��� ���� ��� ���ð� ������� �׳� ���������� �̵�
		}
	}

	if (is_correct == true) { printf("Correct"); }
	else { printf("Incorrect"); }
	
	free(mystack->ch);
	free(mystack);
	return 0;
	/*
	* 
	while (*input) { //������� ������
		if (is_correct == false) { break; } //false�� �Ǹ� �ݺ��� ������
		switch (*input) //*input �� ����
		{
		case '<': case '{': case '[':
			push(mystack, *input);
			break;
		case '>':
			if (pop(mystack) != '<') { is_correct = false; }
			break;
		case '}':
			if (pop(mystack) == '{') { break; }
			else {
				is_correct = false;
				break;
			}
		case ']':
			if (pop(mystack) == '[') { break; }
			else {
				is_correct = false;
				break;
			}
		default:
			break; //�̿��� ���� ��� ���ð� ������� �׳� ���������� �̵�
		}
		input++; // �ڷ� �̵�
	}
	* 
	* 
	*/
}
/* input++ �̷��� ���ڹ迭 �ٷ� �� ���� ����? strcpy�� ���� ���ڿ� ����� ����������.
	���ڿ� �Է¹޴� ���� �� �� ���� --?????? �³�....
*/