/* 문자배열 메모리 할당 */
/* 주의-- 문자열 메모리 할당하고 strcpy 하려면,  memset() 함수 사용해서 copy가 가리키는 메모리 버퍼의 모든 값들을 널문자로 설정한다- 
		순서가 malloc 한 후 memset, strcpy, free 순임. */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char original[100]; //원본 문자열
	char* copy = (char*)malloc(sizeof(char)); //문자 배열 메모리 할당
	memset(copy, 0, 100); // 꼭 해줘야됨!!!!

	strcpy(original, "yoonseo");
	puts(original);

	strcpy(copy, original);
	puts(copy);

	free(copy);
	return 0;
}
