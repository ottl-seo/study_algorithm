/* ���ڹ迭 �޸� �Ҵ� */
/* ����-- ���ڿ� �޸� �Ҵ��ϰ� strcpy �Ϸ���,  memset() �Լ� ����ؼ� copy�� ����Ű�� �޸� ������ ��� ������ �ι��ڷ� �����Ѵ�- 
		������ malloc �� �� memset, strcpy, free ����. */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char original[100]; //���� ���ڿ�
	char* copy = (char*)malloc(sizeof(char)); //���� �迭 �޸� �Ҵ�
	memset(copy, 0, 100); // �� ����ߵ�!!!!

	strcpy(original, "yoonseo");
	puts(original);

	strcpy(copy, original);
	puts(copy);

	free(copy);
	return 0;
}
