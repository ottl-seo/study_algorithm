/* ���� 21. ���ڿ��� ���ڷ� ��ȯ�ϱ�.
	atoi() �Լ� �̿� */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int num1, num2;
	char *str1 = new char[100]; //�̷��� �ؼ� ���ڿ� �Է¹ޱ� !!!!
	char str2[100];
	strcpy_s(str2, "chu");

	num2 = atoi(str2);
	printf("\n< String 1 >\n%s", str2);
	printf("\n< Integer 1 >\n%d\n", num2);
	
	printf("Input String: ");
	scanf_s("%s", str1, 100); //�Է� �ް�,
	num1 = atoi(str1);
	printf("\n< String >\n%s", str1);
	printf("\n< Integer >\n%d\n", num1);

	return 0;
}

/* 
1.  ���ڿ� ���- �ּҰ����� �μ� �����ؾ��� *string�� �ƴ϶� string����.
	*string �� ��� ù ���� �ϳ��� ��
	
2.  ���ڿ� �Է�
	- ������ ��: char *string = new char[100];
	- scanf���� ���� 3��: scanf_s("%s",string,100);
	
	//�����Ҵ��� ���?
	// atoi �Լ� �� �̻��� .....................
*/