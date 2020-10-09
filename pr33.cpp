/* lesson 36. 문자열을 회전하여 출력하기 */
#include <stdio.h>
#include <string.h>

int main() {
	int i, j;
	char ch;
	char string[100]; //string 정의 시엔	배열로 하는 게 좋음~~

	strcpy_s(string, "String.");
	int len = strlen(string);
	
	for (int i = 0; i < len; i++) {
		ch = string[len - 1]; //ch에 가장 마지막 문자 저장
		for (j = len- 1; j > 0; j--) { //맨 뒤에서부터
			string[j] = string[j - 1]; //한 칸씩 앞으로 밀어
		}
		string[0] = ch; //맨 앞에 저장되지 않았으므로 넣어줌
		printf("[%d] %s\n", i, string);
	}
	return 0;
}