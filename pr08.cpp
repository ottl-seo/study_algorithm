/* 8. ���� �߻�
	- ���� �� 20�� ��� */
#include <stdio.h>
#include <stdlib.h>

int main() {
	int start, end;
	int x, num; // ���� ���� �� ����� x, ���� num
	printf("���۰��� �Է��ϼ���: ");
	scanf_s("%d", &start);
	printf("���ᰪ�� �Է��ϼ���: ");
	scanf_s("%d", &end);
	
	x = end - start + 1; // ���ᰪ-���۰� +1
	for (int i = 0; i < 20; i++) {
		num = rand() % x + start; //start���� ���� ������ �����ش�.
		printf("\n%d", num);
	}
	return 0;
}

/* ���� �߻� ���: <stdlib.h>�� rand() �Լ�
	 rand() % 10 // 0~9������ ���� �߻�
	 rand() % 50 // 0~49
	 rand() % 50 + 10 // 10~49
*/