/* å ���� 20. ���� ���� ����(left)
	(isspace(*str)==1)�̸�, ...~  */
#include <stdio.h>
#include <string.h>
#include <ctype.h> //isspace() �Լ�
// #include <stdlib.h> --malloc ��� ���°���....

char* remove_sp(char* strr);

int main(){
	//char* strr = (char*)malloc(sizeof(char)); //���ڿ�
	char strr[100];
	char* tlqkf;
	/*
	printf("Input String: ");
	scanf_s("%s", strr); //�Է¹ޱ� %s, ������ ������ ����
	*/
	strcpy_s(strr, "\n\t  hi");
	printf("<< Before >>%s\n", strr);
	tlqkf = remove_sp(strr);
	printf("<< After >>\n%s", tlqkf);

	return 0;
}
char* remove_sp(char* strr) {
	int i = 0;
	char ch = *(strr + i);

	while (*strr) {
		if (!isspace(*strr) == 1) { return strr; } //��ũ �ƴϸ� �״�� ����
		else
			*strr++;
	}
	return (char*)""; //�� ���ڿ� ����
}