/* memcpy ���� 
	memcpy�� �޸� ������ �����ϴ� �Լ� */

#include <stdio.h>
#include <string.h>

int main() {
	char str1[] = "Sample String";
	char str2[40];
	char str3[40];

	memcpy(str2, str1, strlen(str1) + 1);
	memcpy(str3, "copy successful!", 17);

	printf("str1: %s\n",str1);
	printf("str2: %s\n",str2);
	printf("str3: %s\n", str3);

	return 0;
}

/*
1��° memcpy �Լ��� str2 �� str1 �� ���ڿ� ���� + 1 (���� �� ���� ������ 1�� ������)
	��ŭ�� str2 �� ������ �ִ´�.
2��° memcpy �Լ��� str3 �� "copy successful\0" �� ������ �ִ´�.
*/