/* 문자열 좌우 추출 */
//#define 

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
	printf("%s", string);
	p = strLeft(string, 2);
	printf("%s", p);
	
	p = strRight(string, 2);
	printf("%s", p);

	return 0;
}
char* strLeft(char* string, int len) {
	char* p = strdup(string);
	p[len] = 0;
	return p;
}
char* strMid(char* string, int pos) {
	return strdup(&string[pos]);
}
char* strRight(char* string, int len) {
	int n = strlen(string);
	return strdup(&string[n - len]);
}
