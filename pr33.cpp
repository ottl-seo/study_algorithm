/* lesson 36. 문자열을 회전하여 출력하기 */
#include <stdio.h>
#include <string.h>

int main() {
	int i, j;
	char ch;
	char string[100]; //string 정의 시엔	배열로 하는 게 좋음~~

	strcpy(string, "String.");
	
	for (int i = 0; i < strlen(string); i++) {
		ch = string[strlen(string) - 1];
		for (j = strlen(string) - 1; j > 0; j--) {
			string[j] = string[j - 1];
		}
		string[0] = ch;
		printf("[ %d] %s\n"i, string);
	}
	return 0;
}
