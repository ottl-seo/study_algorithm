/* 23�� ���� �����ϰ� å ����.. ���Ϻ��� ��Ǯ��
	����23. ���ڸ� 2/10/16�� ���ڿ��� ��ȯ�ϱ� */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	//char string[100];

/* // å Ǯ��) itoa ǥ���Լ��� �ƴ϶� ������ ...?
	
	itoa(255, string, 2); //255 ���ڸ� 2�� ���ڿ��� ��ȯ(itoa)
	printf("[255] -> [%s]2", string);

	itoa(255, string, 10); //10�� ���ڿ��� ��ȯ(itoa)
	printf("[255] -> [%s]10", string);

	itoa(255, string, 16); //16�� ���ڿ��� ��ȯ(itoa)
	printf("[255] -> [%s]16", string);

	itoa(65535, string, 2); //65535�� 2�� ���ڿ��� ��ȯ(itoa)
	printf("[65535] -> [%s]2", string);

	itoa(65535, string, 10); //65535�� 2�� ���ڿ��� ��ȯ(itoa)
	printf("[65535] -> [%s]10", string);

	itoa(65535, string, 16); //65535�� 2�� ���ڿ��� ��ȯ(itoa)
	printf("[65535] -> [%s]16", string);
*/
/* ---------- sprintf ��� -----------
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
	sprintf_s(buf, "%s", integer); //123�� string���� ��ȯ�غ��� --�� ��
	printf("%s \n", buf);
	*/
	sprintf_s(buf, "%o", integer); //10����->8���� ��, buf ���ڿ��� ����
	printf("%o \n", buf);
	return 0;
}
