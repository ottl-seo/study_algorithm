/* å ���� 14. ���� �˻� �Լ� ����� */

#include <stdio.h>
#include <string.h>

char* strChr(const char* pstring, char ch);

int main() {
	char string[100];
	char* position_1; 
	char* position_2;

	strcpy_s(string, "My name is Yoonseo."); //string �� ����
	position_1 = strchr(string, 'a'); // <string.h>�� ����Ǿ��ִ� ���� �˻� �Լ� -- position���� �ε��� ���� ��
	printf("%d ��ġ�� a�� ����\n", position_1 - string); // string�� ���ڿ� �迭�� ���� ��ġ ��Ÿ���Ƿ�..

	position_2 = strChr(string, 'a');
	printf("%d ��ġ�� a�� ����\n", position_2 - string);
	
	return 0;
}
char* strChr(const char* pstring, char ch) {
	
	while (*pstring && *pstring != ch) { // *pstring�� ������ �ʾ��� �� && *pstring�� ch�� �ƴ� ��
		pstring++;
	}
	if (*pstring == ch) //ch�� *pstring �Ѵ� ���ڿ��� �ƴ϶� ���� �ϳ� �̹Ƿ� == ������ ����
		return (char*)pstring; //�ּҰ����� ����???
	return (char*)0;
}