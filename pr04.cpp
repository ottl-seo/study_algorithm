/* 4. ������ ����ϱ� */

#include <stdio.h>
int main() {
	int n;
	printf("Input n: "); //���� ���� �Է� �ޱ�
	scanf_s("%d", &n);

	// �� �ﰢ��
	for (int i = 0; i < n; i++) { // n��
		for (int b = 0; b < (n - i); b++) //blank
			putchar(' ');
		for (int s = 0; s < (2 * i - 1); s++) //star
			putchar('*');
		putchar('\n');
	}
	// �Ʒ� �ﰢ��
	for (int i = n; i > 0; i--) {
		for (int b = 0; b < (n - i); b++) //blank
			putchar(' ');
		for (int s = 0; s < (2 * i - 1); s++) //star
			putchar('*');
		putchar('\n');
	}
	return 0;
}

// �Լ�ȭ�� ���� ����
// �� ���� ������ �� �� ���ϴ�
// blank�� star�� ��ü�� �� ���� ���� X -- ���ٿ� ������ �� �ݺ���ȭ �ϴ� ����