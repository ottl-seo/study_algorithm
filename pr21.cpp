/* 예제 21. 문자열을 숫자로 변환하기.
	atoi() 함수 이용 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int num1, num2;
	char *str1 = new char[100]; //이렇게 해서 문자열 입력받기 !!!!
	char str2[100];
	strcpy_s(str2, "chu");

	num2 = atoi(str2);
	printf("\n< String 1 >\n%s", str2);
	printf("\n< Integer 1 >\n%d\n", num2);
	
	printf("Input String: ");
	scanf_s("%s", str1, 100); //입력 받고,
	num1 = atoi(str1);
	printf("\n< String >\n%s", str1);
	printf("\n< Integer >\n%d\n", num1);

	return 0;
}

/* 
1.  문자열 출력- 주소값으로 인수 전달해야함 *string이 아니라 string으로.
	*string 일 경우 첫 문자 하나가 됨
	
2.  문자열 입력
	- 정의할 때: char *string = new char[100];
	- scanf에서 인자 3개: scanf_s("%s",string,100);
	
	//동적할당은 어떻게?
	// atoi 함수 좀 이상함 .....................
*/