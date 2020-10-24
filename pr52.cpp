/* 문자열 좌우 추출 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strLeft(char* string, int len);
char* strMid(char* string, int pos);
char* strRight(char* string, int len);

int main() {
	char string[100];
	char* p;

	strcpy(string, "yoonseo");
	puts(string);
	p = strLeft(string, 2);
	puts(p);
	free(p); //strLeft 내부에서 _strdup() 함수가 사용되었으므로 메모리 해제해준다
	
	p = strRight(string, 3); //오른쪽 세글자 seo 추출
	puts(p);
	free(p);

	return 0;
}
char* strLeft(char* string, int len) {
	char* p = _strdup(string);
	p[len] = 0;
	return p;
}
char* strRight(char* string, int len) {
	int n = strlen(string);
	return _strdup(&string[n - len]);
}

//이건 참고용. position 입력하면 그 위치의 문자 추출해줌
char* strMid(char* string, int pos) {
	return _strdup(&string[pos]);
}

