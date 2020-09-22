#include <stdio.h>
#include <stdlib.h>

int main() {
	int size;
	int* arr = NULL;
	int sum = 0;
	double avg = 0.0;
	int i;

	printf("How many numbers?");
	scanf_s("%d", &size); //ũ�⸦ �� �Է¹޴°���

	arr = (int*)malloc(sizeof(int) * size); //�Է¹��� ũ�⸸ŭ ���� �迭

	if (arr == NULL) {
		printf("--���� �޸� �Ҵ� ����--\n");
		return -1;
	}
	printf("Input %d numbers: ", size);
	for (int i = 0; i < size; i++)
		scanf_s("%d", (arr+i)); // &arr[i]
	for (i = 0; i < size; i++)
		sum += *(arr + i);

	avg = (double)sum / (double)size;
	printf("sum = %d, avg = %.2f\n", sum, avg);

	free(arr); //�ݵ�� �������� ��
	return 0;
}

/*
	& + * == 0;
	arr[i] == *(arr+i);
*/