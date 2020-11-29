/* Shell sort (�� ����) 
	- insertion ������ ������ ���� (using gap)
	- �ð����⵵: ���= O(n^1.5), �־�= O(n^2)
	*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

/* insertion_sort�� ���� */
void inc_insertion_sort(int list[], int first, int last, int gap) {
	int i, j, key;
	for (i = first; i <= last; i += gap) { // i<=last �� �� ����. // i+=gap �߿�!!!
		key = list[i];
		for (j = i - gap; j >= first && list[j] > key; j -= gap) // j= i-gap �߿�! 
			list[j + gap] = list[j]; //�ݺ��� ������
		list[j + gap] = key; // 
	}
}
void shell_sort(int list[], int n) {
	for (int gap = n / 2; gap > 0; gap /= 2) {
		if (gap % 2 == 0) { gap++; } //gap�� Ȧ���� �� ���� ����
		for (int i = 0; i < gap; i++)
			inc_insertion_sort(list, i, n - 1, gap); // i, n-1 �� �� ����!!!!
	}
}
int main() {
	int list[MAX_SIZE];
	int i, n;
	n = MAX_SIZE;
	srand(time(NULL));

	for (i = 0; i < n; i++)
		list[i] = rand() % 100; // 0~99
	printf("\n< Before Sorting >\n");
	for (i = 0; i < n; i++)
		printf("%d ", list[i]); //���� �� ����Ʈ ���

	shell_sort(list, n); // �� ���� ȣ��
	printf("\n\n< After Shell Sorting >\n");
	for (i = 0; i < n; i++)
		printf("%d ", list[i]); //���� �� ����Ʈ ���
	printf("\n");

	return 0;
}