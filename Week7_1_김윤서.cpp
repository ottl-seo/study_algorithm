#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct QueueNode { //ť�� ���� ��� 1��
	element data; //����� data��
	QueueNode* link; //����� link��
}QueueNode;
typedef struct QueueType {
	QueueNode* front; // ť ��ü���� front�� ���
	QueueNode* rear; //rear ���
}QueueType;

void printInfo();
void error(const char* message);
void init(QueueType* q);
bool is_empty(QueueType* q);
void enqueue(QueueType* q, element item);
element dequeue(QueueType* q);

int main() {
	printInfo(); //���� ���
	
	int num, result = 0; //�Է¹��� ��, �����=0
	QueueType fibo; //ť ����
	init(&fibo);
	enqueue(&fibo, 0); // f(0)=0 ����
	enqueue(&fibo, 1); // f(1)=1 ����

	printf("Input a fibonicci location: ");
	scanf_s("%d", &num); //�Է� �޴´�

	for (int i = 0; i <= num; i++) {
		result += dequeue(&fibo); //result���� �����ش�
		enqueue(&fibo, result); // ���� ���� �����ֱ� ���� ť�� �־��ش�
		printf("   %3d", result);
	}
	printf("\n");
	return 0;
}

void error(const char* message) { //���� ��� �Լ�
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void init(QueueType* q) { //ť �ʱ�ȭ �Լ�
	q->front = q->rear = NULL; // front�� rear�� ��� NULL�� ����
}
bool is_empty(QueueType* q) {
	return (q->front == NULL); // front�� rear�� NULL�̸� empty
}
void enqueue(QueueType* q, element item) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode)); //�� ��� ����
	temp->data = item; //data�� �� �ְ�
	temp->link = NULL; // link�� NULL��.
	if (is_empty(q)) { //q�� ������� ���, front�� rear�� ��� temp�� ���Ѵ�
		q->front = q->rear = temp;
	} else {
		q->rear->link = temp; //rear�� link�� temp ����
		q->rear = temp; //q�� rear�� temp�� �����Ѵ�.
	}
}
element dequeue(QueueType* q) {
	if (is_empty(q)) { error("Queue is empty"); }
	element data; // ���� ����� ������ ��ȯ�� ��
	QueueNode* temp = q->front; //���� ��带 ������ �� ��� ����
	data = temp->data;
	q->front = q->front->link; //front�� ���� ������ �Ű��ش�
	if (q->front == NULL) { q->rear = NULL; } //q�� ��尡 �� �� �ִ� ����� queue�� �������� �������
	free(temp); //���� ��带 free ���ش�
	return data; //���� ����� ������ �� ��ȯ
}
void printInfo(void) {
	printf("====================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971063\n");
	printf("����: ������\n");
	printf("====================\n");
}