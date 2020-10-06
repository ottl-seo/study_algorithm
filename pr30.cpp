/* pr28 고친 ver-
pr29는 함수로 뺀거, 이건 메인에 넣은건데 코드 똑같은데 대체 왜안되는건지 알수없음 그냥 기억하고 함수로 빼자 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef char element; //element는 char 타입
typedef struct stack {
	element ch[MAX]; //문자 배열. 여기에 쌓는다.
	int top; //최고 원소의 인덱스
}stack;

void init(stack* s) { //스택 초기화 함수
	s->top = -1;
}
void error(const char* message) {
	fprintf(stderr, message); //오류 메시지 출력 함수
}
bool is_full(stack* s) {
	if (s->top == MAX) { return true; }
	else { return false; }
}
bool is_empty(stack *s){
	if (s->top == -1) { return true; }
	else { return false; }
}
element pop(stack* s) {
	if (is_empty(s)) {
		error("Stack Empty");
		exit(1);
	}
	else {
		return (s->ch[s->top--]); //top이 나중에 --, data는 배열이므로 []
	}
}
void push(stack* s, element value) {
	if (is_full(s)) {
		error("Stack Overflow");
		return;
	}
	else {
		s->ch[++(s->top)] = value; // ++먼저, s->data의 top 값에 value 저장.
	}
}

//------------------------------main-----------------------------------
int main(){
	char input[MAX]; //입력받을 땐 동적할당말고 배열[MAX]로 지정...?!
	int i = 0; int length = 0; //for문에 사용
	bool is_correct = true; //초기값 true로 지정. 근데 이렇게 하는것보다 함수로 빼고 리턴하는게 더 좋음
	char ch, pop_ch;

	stack* mystack = (stack*)malloc(sizeof(stack)); //mystack 정의

	printf("Input expression\n");
	scanf_s("%s", input);

	length = strlen(input); //이거 good
	for (int i = 0; i > length; i++) {
		if (is_correct == false) { break; } //반복 중에 false가 되면 빠져나간다
		ch = input[i];
		switch (ch)
		{
		case '<': case '{': case '[':
			push(mystack, ch);
			break;
		case '>': case ')': case ']': //닫는 괄호
			if (is_empty(mystack)) { is_correct = false; }
			else {
				pop_ch = pop(mystack);
				if (((pop_ch == '<') && (ch != '>')) ||
					((pop_ch == '{') && (ch != '}')) ||
					((pop_ch == '[') && (ch != ']')))
					is_correct = false;
			}
			break;
		default:
			break; //이외의 값일 경우 스택과 관계없이 그냥 다음값으로 이동
		} //switch end
	} //for end

	if (is_correct == true) { printf("Correct"); }
	else { printf("Incorrect"); }
	
	free(mystack);
	return 0;
}
/* input++ 이렇게 문자배열 다룰 수 있을 때는? strcpy를 통해 문자열 제대로 정해졌을때.
	문자열 입력받는 경우는 할 수 없음 --?????? 맞나.... 이것도 물어보기.
*/
