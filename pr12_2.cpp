#include <stdio.h>
#include <stdlib.h>

int main() {
	int size;
	int* arr = NULL;
	int sum = 0;
	double avg = 0.0;
	int i;

	printf("How many numbers?");
	scanf_s("%d", &size); //크기를 왜 입력받는거지

	arr = (int*)malloc(sizeof(int) * size); //입력받은 크기만큼 정수 배열

	if (arr == NULL) {
		printf("--동적 메모리 할당 실패--\n");
		return -1;
	}
	printf("Input %d numbers: ", size);
	for (int i = 0; i < size; i++)
		scanf_s("%d", (arr+i)); // &arr[i]
	for (i = 0; i < size; i++)
		sum += *(arr + i);

	avg = (double)sum / (double)size;
	printf("sum = %d, avg = %.2f\n", sum, avg);

	free(arr); //반드시 해제해줄 것
	return 0;
}

/*
	& + * == 0;
	arr[i] == *(arr+i);
*/