/* 11번 문자열 붙이기 응용
	- 문자열 포인터 */
#define _CRT_SECURE_NO_WARNINGS // strcat 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <string.h>
#include <stdlib.h> //malloc함수가 선언된 헤더

int main() {
	char* s1 = "world"; //이번엔 배열 크기 넉넉히 잡아주는 것이 아니라 포인터로 문자열 선언
	//char* s2 = "Hello"; 

	// strcat(s2, s1); //실행 에러. 
	/* 왜? s2는 읽기 전용 메모리라서, 문자열 붙일 공간이 없음
		-> malloc 동적 메모리 할당해주기 */

	char* s2 = malloc(sizeof(char) * 20); //char 20개 크기만큼 동적 메모리

	strcpy(s2, "Hello"); // s2="Hello"; 메모리가 할당된 문자열 포인터에는 =로 직접 할당할 수 없음
	
	strcat(s2, s1); //s2에 s1 붙이기
	printf("%s\n", s2);
	free(s2); //동적 메모리 해제

	return 0;
}

/*
9줄) 오류 E0144	"const char *" 형식의 값을 사용하여 "char *" 형식의 엔터티를 초기화할 수 없습니다.	pr11_2	C:\Users\a\source\repos\pr11_2\pr11_2\pr11_2.cpp	9

뭐지 - 동적 할당, 문자열 포인터 다시 알아보기..
*/