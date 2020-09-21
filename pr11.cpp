/* 코딩도장 예제. 문자열 붙이기
	- 일반 문자열 */
#define _CRT_SECURE_NO_WARNINGS // strcat 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <string.h>

int main() {
	char s1[10] = "world";
	char s2[20] = "Hello"; //s1과 붙여서 저장할 것이므로 크기 크게

	strcat(s2, s1); //s1과 s2 붙여서 s2에 저장
	
	printf("%s\n", s2); 
	
	return 0;
}