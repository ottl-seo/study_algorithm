/* ���� 20-2. ���ڿ� ������ ���� ���ֱ�  */
// strlen �̿��ϱ�~~~
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* remove_right(char* strr); //������ ���� ���ֱ� �Լ�

int main() {
	char strr[100]; //
	char* strm;
	strcpy_s(strr, "hi \t"); //strr�� �� ����
	
	strm = remove_right(strr);
	printf("<< Before >>\n[%s]", strr);
	printf("\n------\n<< After >>\n[%s]", strm);
	printf("\n------");

	return 0;
}
char* remove_right(char* strr) {
	char* start = strr;
	while (*strr) { //���ڿ� �������� ��- ���� �̷���
		strr++; //������
	}
	strr--; //�ϳ� �ٿ��ְ�,
	while (start <= strr) {
		if (!isspace(*strr)) {
			*++strr = '\0';
			return start;
		}
		strr--;
	}
	return strr;
}