/* 2진/16진 문자열을 숫자로 변환하기 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char string[100];
	char* stop;
	unsigned n;

	strcpy_s(string, "11111111");
	n = strtol(string, &stop, 2); //2진수로 변환해서 stop의 주소값에 넣는다
	printf("%d\n", n);

	strcpy_s(string, "1111111111");
	n = strtol(string, &stop, 2);
	printf("%d\n", n);

	strcpy_s(string, "ff");
	n = strtol(string, &stop, 16); //16진수로
	printf("%d\n", n);

	return 0;
}
// char str[100]; 으로 정의하고 strcpy(str,""); 으로 값 넣는게 오류 없이 잘 됨