/* 예제 20-2. 문자열 오른쪽 공백 없애기  */
// strlen 이용하기~~~
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* remove_right(char* strr); //오른쪽 공백 없애기 함수

int main() {
	char strr[100]; //
	char* strm;
	strcpy_s(strr, "hi \t"); //strr에 값 저장
	
	strm = remove_right(strr);
	printf("<< Before >>\n[%s]", strr);
	printf("\n------\n<< After >>\n[%s]", strm);
	printf("\n------");

	return 0;
}
char* remove_right(char* strr) {
	char* start = strr;
	while (*strr) { //문자열 남아있을 때- 조건 이렇게
		strr++; //끝까지
	}
	strr--; //하나 줄여주고,
	while (start <= strr) {
		if (!isspace(*strr)) {
			*++strr = '\0';
			return start;
		}
		strr--;
	}
	return strr;
}