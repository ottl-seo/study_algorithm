/* 6. ������ �칰 Ż���ϱ� 
	- �����̰� 7m�� �̵��� ��, 3m�� ������ �̲����� ��, �� ȸ���� Ż���ϴ°�?
*/
#include <stdio.h>

int main() {
	int tall = 0; //�����̰� �̵��� ����
	int count = 0; //�� ȸ���� ī��Ʈ
	while (1) { //���ѹݺ�, tall�� 100 �̻��� �Ǹ� break
		count++;
		tall += 7; //7m �̵�
		if (tall >= 100){
			printf(" [%2d] ������: %3dm\n", count, tall); //����ϰ� break
			break;
		}
		else
			tall -= 3; //3m �̲�����
		printf(" [%2d] ������: %3dm\n", count, tall);
	}
	printf("�ҽ��� �����̴� %2dȸ ���� �칰�� Ż���ߴ�ϴ�.\n", count);
	return 0;
}