/* ���� �߻��� */
/* ���� �˰���- ������ �̿��� ī�� ���� ;���� */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define NUM 52

int main() {

	srand(time(NULL));
	printf("---------[0~32767]--------\n");
	for (int i = 1; i <= 5; i++) { printf("���� %2d : %5d\n", i, rand()); }
	printf("---------[0~9]--------\n");
	for (int i = 1; i <= 5; i++) { printf("���� %2d : %5d\n", i, rand() % 10); }
	printf("---------[50~59]--------\n");
	for (int i = 1; i <= 5; i++) { printf("���� %2d : %5d\n", i, rand() % 10 + 50); }

	return 0;
}

/*
int main() {
	int card_num;
	int flag;
	int count = 0;
	int card[NUM] = { 0 }; //ī�带 ���� �迭

	srand(time(NULL)); //srand �Լ��� �̿��� ������ �ʱ�ȭ. ����ø��� �ʱⰪ�� �޶����� �ϱ� ���� time�� ������ �ʱ�ȭ�Ѵ�
	
	while (count < NUM) {
		card_num = rand() % NUM + 1; //
		
		for (int i = 0; i < count; i++) {
			flag = 0;
			if (card[i] == card_num) { flag = 1; break; }
		}
		if (flag == 0) {
			card[count++] = card_num;
			printf("%2d ", card_num);
			if (count % 10 == 0) { printf("\n"); }
		}
	}
	return 0;
}
*/