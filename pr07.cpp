/* 7. �Ǽ� 10�� �Է¹޾� �հ�, ��� ���ϱ� */

#include <stdio.h>
int main() {

	double input; //�Է¹��� �Ǽ�
	double sum = 0;

	for(int i=0;i<10;i++){
		printf("%d��° ��: ", i + 1);
		scanf_s("%f", &input);
		sum += (double)input;
	}
	printf("\n�հ�: %f", sum);
	printf("\n���: %f", (double)sum / (double)10);

	return 0;
}

// �����÷ο� �ذ� how ?