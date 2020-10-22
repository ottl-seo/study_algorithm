#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct QueueNode {
	element num; //�����ͺ�
	QueueNode* link; //����
}QueueNode;
typedef struct QueueType {
	QueueNode* front; //front ���
	QueueNode* rear; //rear ���
}QueueType;

void printInfo();
void error(const char* message);
void init(QueueType* q);
bool is_empty(QueueType* q);
void enqueue(QueueType* q, element item);
element dequeue(QueueType* q);
void print_queue(QueueType* q);
int node_num(QueueType* q);

int main() {
	printInfo(); //���� ���

	int N; //N���� ī��
	element t1, t2; //���� ī��, �Ʒ��� �ű� ī��
	QueueType* q = (QueueType*)malloc(sizeof(QueueType));
	init(q);

	printf("Input number of cards: ");
	scanf_s("%d", &N);
	if (N == 0) { //�Է°��� 0�̸�
		printf("queue empty\n");
		return 0; //����
	}
	for (int i = 0; i < N; i++) { enqueue(q, i + 1); } // 1���� N������ ī�带 ť�� �ִ´�

	while (node_num(q) != 1) { // ť�� �ϳ� ���� ������
		print_queue(q);
		t1 = dequeue(q); //�� �� ī�带 ������
		print_queue(q);
		t2 = dequeue(q); //���� ī�� t2�� ����
		enqueue(q, t2); //t2�� ���� �ڷ� �ִ´�
	}
	printf("Final element is %d\n", q->rear->num); //������ ī�� ��ȣ ���
	
	free(q); //�����Ҵ��� ť�� Ǯ���ش�
	return 0;
}
void init(QueueType* q) {
	q->front = q->rear = NULL; //ť �ʱ�ȭ �Լ�
}
void error(const char* message) {
	fprintf(stderr,"%s\n", message);
	exit(1);
}
bool is_empty(QueueType* q) {
	return (q->front == NULL);
}
void enqueue(QueueType* q, element item) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->num = item;
	temp->link = NULL;
	if (is_empty(q)) { q->front = q->rear = temp; } //q�� ������� ���
	else {
		q->rear->link = temp; //rear�� link�� temp ����
		q->rear = temp; //q�� rear�� temp�� �����Ѵ�.
	}
}
element dequeue(QueueType* q) {
	if (is_empty(q)) { error("queue is empty"); }
	QueueNode* temp = q->front;
	element data = temp->num; //��ȯ�� ��

	if (q->front->link == NULL) { //q�� ���Ұ� �ϳ��� ���
		q->front = q->rear = NULL; //ť�� ��� ���·� ���ش�
	}
	else { q->front = q->front->link; } //front ��ġ�� �ٲ��ش�

	free(temp); //temp�� free ���ش�
	return data;
}
void print_queue(QueueType* q) { //ť ����Ʈ �Լ�
	QueueNode* temp = q->front;
	while (temp != NULL) {
		printf("  %3d  |", temp->num);
		temp = temp->link;
	}
	printf("\n");
}
int node_num(QueueType* q) { //���Ḯ��Ʈ �����ּҸ� �޾� ����� ������ ��ȯ�ϴ� �Լ�
	QueueNode* node = q->front;
	int count = 0;
	while (node != q->rear) { //
		count++;
		node = node->link;
	}
	return (count + 1);
}
void printInfo(void) {
	printf("====================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971063\n");
	printf("����: ������\n");
	printf("====================\n");
}