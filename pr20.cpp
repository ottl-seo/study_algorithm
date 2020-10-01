/* 책 예제 20. 공백 문자 제거(left)
	(isspace(*str)==1)이면, ...~  */
#include <stdio.h>
#include <string.h>
#include <ctype.h> //isspace() 함수
// #include <stdlib.h> --malloc 어떻게 쓰는거지....

char* remove_sp(char* strr);

int main(){
	//char* strr = (char*)malloc(sizeof(char)); //문자열
	char strr[100];
	char* tlqkf;
	/*
	printf("Input String: ");
	scanf_s("%s", strr); //입력받기 %s, 포인터 참조는 없다
	*/
	strcpy_s(strr, "\n\t  hi");
	printf("<< Before >>%s\n", strr);
	tlqkf = remove_sp(strr);
	printf("<< After >>\n%s", tlqkf);

	return 0;
}
char* remove_sp(char* strr) {
	while (*strr) {
		if (!isspace(*strr) == 1) { return strr; } //블랭크 아니면 그대로 리턴
		else
			*strr++;
	}
	return (char*)""; //빈 문자열 리턴
}
