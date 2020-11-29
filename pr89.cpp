/* 2. insertion sort (���� ����)
	: (��) - (�̵�1) - (�̵�2) �� ������ ����
	- for(j=i-1; ...; j--) �� "��" �κп��� ȿ���� ���� (n-1 + n-2 + ... + 1 = O(n^2) )
	- �ּ�= O(n), �־�= O(n^2) 
	- ������ ���� ���
	*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

void insertion_sort(int list[], int n) {
	int i, j, key;
	for (i = 1; i < n; i++) { //0��° ���Ҵ� ���ĵǾ��ٰ� ����!! (1������ �ϴ°� ����)
		key = list[i];  // i��° ���Ұ� key

		for (j = i - 1; j >= 0 && list[j] > key; j--) //���ϴ� �κ�. // j-- �߿�
			list[j + 1] = list[j]; // (key�� 1�� ��,) 3 5 5 8 10 �̷� ������ �ǵ���.  /* �̵�1 */
			/*�̰� ��� �ݺ�. j<0�̰ų� list[j]�� key���� ���� ���� ������*/

		list[j + 1] = key; // �ݺ��� ���� ��ġ�� key ����  /* �̵�2 */
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

	insertion_sort(list, n); //�������� ȣ��
	printf("\n\n< After Selection Sorting >\n");
	for (i = 0; i < n; i++)
		printf("%d ", list[i]); //���� �� ����Ʈ ���
	printf("\n");

	return 0;
}