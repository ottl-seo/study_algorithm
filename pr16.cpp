/* 책 예제 14. 문자 검색 함수 만들기 */

#include <stdio.h>
#include <string.h>

char* strChr(const char* pstring, char ch);

int main() {
	char string[100];
	char* position_1; 
	char* position_2;

	strcpy_s(string, "My name is Yoonseo."); //string 에 복사
	position_1 = strchr(string, 'a'); // <string.h>에 내장되어있는 문자 검색 함수 -- position에는 인덱스 값이 들어감
	printf("%d 위치에 a가 있음\n", position_1 - string); // string은 문자열 배열의 시작 위치 나타내므로..

	position_2 = strChr(string, 'a');
	printf("%d 위치에 a가 있음\n", position_2 - string);
	
	return 0;
}
char* strChr(const char* pstring, char ch) {
	
	while (*pstring && *pstring != ch) { // *pstring이 끝나지 않았을 때 && *pstring이 ch가 아닐 때
		pstring++;
	}
	if (*pstring == ch) //ch랑 *pstring 둘다 문자열이 아니라 문자 하나 이므로 == 연산자 가능
		return (char*)pstring; //주소값으로 전달???
	return (char*)0;
}