/* ũ�������� ���� Ʈ�� ����� */
#include <stdio.h>
#include <stdlib.h>
#define STARS 9

int main() {
	int level, m; //��
	int st, blank; //star, blank
	for (level = 0; level < STARS; level++) {
		printf("\t");
		for (blank = 0; blank < (STARS - level); blank++)
			printf(" ");
		for (st = 0; st < (2 * level - 1); st++)
			printf("*");
		printf("\n");
	}
	printf("\n\t Merry Christmas!\n");
	printf("\n\n\n\t ...^^ ���� �ڿ�??\n\n\n\n\n");
	return 0;
}

