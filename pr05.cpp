/* 5. 19�� ����ϱ�.
- �� ���� ��µ� ������ ���ͷ� �ѱ�� �ϱ� */

#include <stdio.h>

int main() {
	for (int dan = 1; dan <= 19; dan++) {
		printf("[ %d�� ��� ]\n",dan);
		for (int i = 1; i <= 19; i++)
			printf("%2d * %2d = %3d\n", dan, i, dan * i);
		printf("Enter Ű�� ��������.");

		// ���ͷ� ��� �ѱ�??? --getchar() �̿�
		getchar(); //���� �ϳ� �ް� �Ѿ��
	}
	return 0;
}