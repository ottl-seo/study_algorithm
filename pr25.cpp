/* week 5. Stack 전역 기본 배열 사용 예제 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100 //스택의 최대크기 지정

typedef int element; //원소는 int로 지정
element stack[MAX_STACK_SIZE]; //1차원 int 배열
int top = -1; //초기상태 top은 -1

void error(const char X[]) { //오류 메시지 출력 함수
	fprintf(stderr, X);
}
bool is_full() {
	return (top == MAX_STACK_SIZE - 1); // top이 최대면 true 반환
}
bool is_empty() {
	return (top == - 1); // top이 -1이면 true 반환
}
element pop(void) {
	if (is_empty()) {
		error("Stack Empty");
		exit(1);
	}
	else { return stack[top--]; } // top 원소값 반환 후 top 위치 조정
}
