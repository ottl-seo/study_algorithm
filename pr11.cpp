/* �ڵ����� ����. ���ڿ� ���̱�
	- �Ϲ� ���ڿ� */
#define _CRT_SECURE_NO_WARNINGS // strcat ���� ���� ���� ������ ���� ����
#include <stdio.h>
#include <string.h>

int main() {
	char s1[10] = "world";
	char s2[20] = "Hello"; //s1�� �ٿ��� ������ ���̹Ƿ� ũ�� ũ��

	strcat(s2, s1); //s1�� s2 �ٿ��� s2�� ����
	
	printf("%s\n", s2); 
	
	return 0;
}