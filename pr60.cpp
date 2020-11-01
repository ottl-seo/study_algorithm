/* memcpy 연습 
	memcpy는 메모리 공간을 복사하는 함수 */

#include <stdio.h>
#include <string.h>

int main() {
	char str1[] = "Sample String";
	char str2[40];
	char str3[40];

	memcpy(str2, str1, strlen(str1) + 1);
	memcpy(str3, "copy successful!", 17);

	printf("str1: %s\n",str1);
	printf("str2: %s\n",str2);
	printf("str3: %s\n", str3);

	return 0;
}

/*
1번째 memcpy 함수는 str2 에 str1 의 문자열 길이 + 1 (끝의 널 문자 때문에 1을 더해줌)
	만큼을 str2 에 복사해 넣는다.
2번째 memcpy 함수는 str3 에 "copy successful\0" 을 복사해 넣는다.
*/