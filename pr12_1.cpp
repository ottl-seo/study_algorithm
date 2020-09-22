/* 동적할당 예제1 -데이터구조 week3 자료 
	전형적인 동적 메모리 할당 코드 */
#include <stdio.h>
#include <stdlib.h>

int main() {
	int size;
	int* arr = NULL; //포인터를 정의할 땐 항상 NULL로 초기화 해주자
	
	scanf_s("%d", &size); //size를 입력받기
	arr = (int*)malloc(sizeof(int) * size); 
		//int의 바이트크기로 arr의 배열 크기 설정

	free(arr); //할당했던 메모리를 해제
}