/* 9. �Էµ� ���� ���� ���� ����ϱ�
	- switch�� ���� */
#include <stdio.h>

int main() {
	int input;
	char grade; // A~F

	printf("<< ���� ���� >>\n");
	printf("������ ����(0~100)�� �Է��ϸ� ������ ����մϴ�.\n");
	printf("( �����ڵ�: 111 )\n");
	printf("--------------------\n");
	
	
	while (1) {
		printf("\n����: ");
		scanf_s("%d", &input);

		if (input == 111) { // ���� �Է� �� ����
			printf("���α׷��� �����մϴ�.\n");
			break;
		}
		switch (input / 10)
		{
		case 10:
		case 9:
			printf("A\n");
			break;
		case 8:
			printf("B\n");
			break;
		case 7:
			printf("C\n");
			break;
		case 6:
			printf("D\n");
			break;
		case 5:
		case 4:
		case 3:
		case 2:
		case 1:
		case 0:
			printf("F\n");
			break;
		default:
			printf("Wrong Input\n");
			break;
		}
	}
	return 0;
}

/* 
	switch���� case�� �����ִ� ���� ������ �� ��
	�� 100-90-80 �̷��� ������ �� �ǰ�, 100-99-98-... �̷��� ��� ���� case�� ��������� ��.
	�׷��� ������ case�� ���������� ���� ���� default case�� ��-> "Wrong Input"

	case 10:
	case 9: //�̷��� �ϸ� ���� ���̽��� �͵� ���.

*/