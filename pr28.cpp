/* 스택의 응용: 괄호쌍 검사 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef char element; //element는 char 타입
typedef struct stack {
	element *ch; //문자 배열. 여기에 쌓는다. init()에서 동적할당 할것
	int capacity; //배열 크기(문자열의 길이)
	int top; //최고 원소의 인덱스
}stack;

void init(stack* s) { //스택 초기화 함수
	s->top = -1;
	s->capacity = 1;
	s->ch = (element*)malloc(s->capacity * sizeof(element));
}
void error(const char* message) {
	fprintf(stderr, message); //오류 메시지 출력 함수
}
bool is_full(stack* s) {
	if (s->top == s->capacity - 1) { return true; }
	else { return false; }
}
bool is_empty(stack *s){
	if (s->top == -1) { return true; }
	else { return false; }
}
element pop(stack* s) { //pop 함수
	if (is_full(s)) {
		s->capacity *= 2; //2배로 늘려주고
		s->ch = (element*)realloc(s->ch, s->capacity * sizeof(element)); //다시 할당해준다
	}
	else { return (s->ch[s->top--]); }
}
void push(stack* s, element item) {
	if (is_empty(s)) {
		error("Stack empty");
		exit(1);
	}
	else {
		s->ch[++(s->top)] = item; //item을 다음 top에 넣어준다
	}
}
int main(){
	char input[MAX]; //입력받을 땐 동적할당말고 배열[MAX]로 지정...?!
	int i = 0; int length = 0; //for문에 사용
	bool is_correct = true;
	stack* mystack = (stack*)malloc(sizeof(stack)); //mystack 정의

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
			break; //이외의 값일 경우 스택과 관계없이 그냥 다음값으로 이동
		}
	}

	if (is_correct == true) { printf("Correct"); }
	else { printf("Incorrect"); }
	
	free(mystack->ch);
	free(mystack);
	return 0;
	/*
	* 
	while (*input) { //비어있지 않으면
		if (is_correct == false) { break; } //false가 되면 반복문 나간다
		switch (*input) //*input 한 글자
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
			break; //이외의 값일 경우 스택과 관계없이 그냥 다음값으로 이동
		}
		input++; // 뒤로 이동
	}
	* 
	* 
	*/
}
/* input++ 이렇게 문자배열 다룰 수 있을 때는? strcpy를 통해 문자열 제대로 정해졌을때.
	문자열 입력받는 경우는 할 수 없음 --?????? 맞나....
*/