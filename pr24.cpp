/* 23번 백준 실패하고 책 예제.. 내일부턴 뭐풀지
	예제23. 숫자를 2/10/16진 문자열로 변환하기 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	//char string[100];

/* // 책 풀이) itoa 표준함수가 아니라서 에러남 ...?
	
	itoa(255, string, 2); //255 숫자를 2진 문자열로 변환(itoa)
	printf("[255] -> [%s]2", string);

	itoa(255, string, 10); //10진 문자열로 변환(itoa)
	printf("[255] -> [%s]10", string);

	itoa(255, string, 16); //16진 문자열로 변환(itoa)
	printf("[255] -> [%s]16", string);

	itoa(65535, string, 2); //65535를 2진 문자열로 변환(itoa)
	printf("[65535] -> [%s]2", string);

	itoa(65535, string, 10); //65535를 2진 문자열로 변환(itoa)
	printf("[65535] -> [%s]10", string);

	itoa(65535, string, 16); //65535를 2진 문자열로 변환(itoa)
	printf("[65535] -> [%s]16", string);
*/
/* ---------- sprintf 사용 -----------
* // sprintf(char* str, const char* format, ...), fprintf()

	sprintf_s(string, "%s", 255);
	printf("%s",string);
	
*/
	int integer = 123;
	char character = 'c';
	char string[] = "hello, world";
	int* pointer = &integer;
	double pi = 3.141592;
	char buf[100];

	sprintf_s(buf, "integer : (decimal) %d (octal) %o \n", integer, integer);
	printf("%s \n", buf);

	sprintf_s(buf, "string : %s \n", string);
	printf("%s \n", buf);

	/*
	sprintf_s(buf, "%s", integer); //123을 string으로 변환해보기 --안 됨
	printf("%s \n", buf);
	*/
	sprintf_s(buf, "%o", integer); //10진수->8진수 후, buf 문자열에 저장
	printf("%o \n", buf);
	return 0;
}
