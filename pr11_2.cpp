/* 11�� ���ڿ� ���̱� ����
	- ���ڿ� ������ */
#define _CRT_SECURE_NO_WARNINGS // strcat ���� ���� ���� ������ ���� ����
#include <stdio.h>
#include <string.h>
#include <stdlib.h> //malloc�Լ��� ����� ���

int main() {
	char* s1 = "world"; //�̹��� �迭 ũ�� �˳��� ����ִ� ���� �ƴ϶� �����ͷ� ���ڿ� ����
	//char* s2 = "Hello"; 

	// strcat(s2, s1); //���� ����. 
	/* ��? s2�� �б� ���� �޸𸮶�, ���ڿ� ���� ������ ����
		-> malloc ���� �޸� �Ҵ����ֱ� */

	char* s2 = malloc(sizeof(char) * 20); //char 20�� ũ�⸸ŭ ���� �޸�

	strcpy(s2, "Hello"); // s2="Hello"; �޸𸮰� �Ҵ�� ���ڿ� �����Ϳ��� =�� ���� �Ҵ��� �� ����
	
	strcat(s2, s1); //s2�� s1 ���̱�
	printf("%s\n", s2);
	free(s2); //���� �޸� ����

	return 0;
}

/*
9��) ���� E0144	"const char *" ������ ���� ����Ͽ� "char *" ������ ����Ƽ�� �ʱ�ȭ�� �� �����ϴ�.	pr11_2	C:\Users\a\source\repos\pr11_2\pr11_2\pr11_2.cpp	9

���� - ���� �Ҵ�, ���ڿ� ������ �ٽ� �˾ƺ���..
*/