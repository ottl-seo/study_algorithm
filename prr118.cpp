/* week5. 구조체의 동적 할당 사용
	 - 구조체 member를 동적할당 하기
	 구조체 멤버를 포인터로 정의, malloc으로 동적메모리를 할당 받아 스택 생성 */
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct StackType {
	element *data; // 스택을 동적으로 할당하고 이를 data가 가리키도록 함
	int capacity; //현재 동적할당 받은 메모리 크기 (++, -- 연산 자체적으로)
	int top; //최고 원소의 인덱스
}StackType;

void init_stack(StackType* s) { //스택 초기화 함수
	s->capacity = 1;
	s->top = -1; //top 초기값은 -1
	s->data = (element*)malloc(s->capacity * sizeof(element)); //element하나의 크기 * 스택의 크기
}
void error(const char* message) {
	fprintf(stderr, message); //오류 메시지 출력
}
bool is_full(StackType* s) {
	return (s->top >= s->capacity - 1); //top이 메모리크기보다 커지면 메모리 포화 상태
}
bool is_empty(StackType* s) {
	return (s->top == - 1); //빈 스택일 경우 (top이 초기상태 -1일 때)
}
element pop(StackType* s) { //꺼내오기
	if (is_empty(s)) {
		error("Stack empty");
		exit(1);
	}
	else { return (s->data[(s->top)--]); } // data[] top 의 값을 리턴하고, top 값 줄여주기
}
void push(StackType* s, element e) {
	if (is_full(s)) { //크기를 동적 할당하므로 스택 오버플로우 발생시키지 않고 늘려주기
		s->capacity *= 2;
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
			//현재 내용을 유지하면서 동적 메모리를 다시 할당-- realloc(현재 데이터, size) 
	}
	s->data[++(s->top)] = e; //top 증가 후 원소값 저장
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

	free(s.data); //s.data는 init()함수 내에서 동적 할당 해줬으므로 풀어준다
	return 0;
}
