/* lesson 36. ���ڿ��� ȸ���Ͽ� ����ϱ� */
#include <stdio.h>
#include <string.h>

int main() {
	int i, j;
	char ch;
	char string[100]; //string ���� �ÿ�	�迭�� �ϴ� �� ����~~

	strcpy_s(string, "String.");
	int len = strlen(string);
	
	for (int i = 0; i < len; i++) {
		ch = string[len - 1]; //ch�� ���� ������ ���� ����
		for (j = len- 1; j > 0; j--) { //�� �ڿ�������
			string[j] = string[j - 1]; //�� ĭ�� ������ �о�
		}
		string[0] = ch; //�� �տ� ������� �ʾ����Ƿ� �־���
		printf("[%d] %s\n", i, string);
	}
	return 0;
}