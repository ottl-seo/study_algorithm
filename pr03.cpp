/* ���ﰢ�� ����ϱ� ���� */
#include <stdio.h>

void triangle(int num); //�Ϲ� �ﰢ�� ���
void upgrade_triangle(int num); //��� ������ �ﰢ�� ���

int main() {
	int num; //���� �Է¹ޱ�
	/**/
	printf("�� ���� ���̸� �Է��ϼ���: ");
	scanf_s("%d", &num);
	
	printf("\n< triangle >\n");
	triangle(num);

	printf("\n< upgrade triangle >\n");
	upgrade_triangle(num);
	
	return 0;
}
void triangle(int num) {
	for (int i = num; i > 0; i--) {
		for (int j = i; j > 0; j--)
			putchar('*');
		putchar('\n');
	}
}
void upgrade_triangle(int num) {
	for (int i = num; i > 0; i-=2) {
		for (int blank = 0; blank < (num - i)/2; blank++) {
			putchar(' ');
		}
		for (int star = 0; star < i; star++) {
			putchar('*');
		}
		putchar('\n');
	}
}

