/* 문자열 연습 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

int main() {
	char ori[MAX]= "yoonseo";
	char str[MAX]; //문자열

	printf("ORIGINAL: %s\n", ori);
	strcpy(str, ori);
	printf("NEW: %s\n", str);

	return 0;	
}

/* 안 되는 것

	char ori[MAX]= "yoonseo";
	char *str=NULL; //문자열

	strcpy(str, ori);S

*/
