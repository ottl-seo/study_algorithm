/* �����Ҵ� ����1 -�����ͱ��� week3 �ڷ� 
	�������� ���� �޸� �Ҵ� �ڵ� */
#include <stdio.h>
#include <stdlib.h>

int main() {
	int size;
	int* arr = NULL; //�����͸� ������ �� �׻� NULL�� �ʱ�ȭ ������
	
	scanf_s("%d", &size); //size�� �Է¹ޱ�
	arr = (int*)malloc(sizeof(int) * size); 
		//int�� ����Ʈũ��� arr�� �迭 ũ�� ����

	free(arr); //�Ҵ��ߴ� �޸𸮸� ����
}