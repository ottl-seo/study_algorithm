/* 2��/16�� ���ڿ��� ���ڷ� ��ȯ�ϱ� */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char string[100];
	char* stop;
	unsigned n;

	strcpy_s(string, "11111111");
	n = strtol(string, &stop, 2); //2������ ��ȯ�ؼ� stop�� �ּҰ��� �ִ´�
	printf("%d\n", n);

	strcpy_s(string, "1111111111");
	n = strtol(string, &stop, 2);
	printf("%d\n", n);

	strcpy_s(string, "ff");
	n = strtol(string, &stop, 16); //16������
	printf("%d\n", n);

	return 0;
}
// char str[100]; ���� �����ϰ� strcpy(str,""); ���� �� �ִ°� ���� ���� �� ��