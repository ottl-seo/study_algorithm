/* week7-4 ����: �迭 �̿��� ��
	== ���� ť ADT�� �����! */
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX];
}DequeType;

void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void init(DequeType* dq) {
	dq->front = dq->rear = 0; //���� ť�� ����
}
bool is_full(DequeType* dq) {
	return ((dq->rear + 1) % MAX == dq->front); //���� ť�� ����
}
bool is_empty(DequeType* dq) {
	return (dq->front == dq->rear);
}
void add_rear(DequeType* dq, element item) {
	if (is_full(dq)) { error("deque is full"); }
	dq->rear = (dq->rear + 1) % MAX; //�ϳ� ���������ְ�
	dq->data[dq->rear] = item;
}
void add_front(DequeType* dq, element item) {
	if (is_full(dq)) error("deque is full");
	dq->data[dq->front] = item;
	dq->front = (dq->front - 1+MAX) % MAX; //front �ڸ��� ���� �ְ� front�� ���� ������
}
element get_rear(DequeType* dq) {
	if (is_empty(dq))error("deque is empty"); //������� ��� ����
	return dq->data[dq->rear]; //�� ��ȯ, rear ��ġ�� �״��
}
element get_front(DequeType* dq) {
	if (is_empty(dq))error("deque is empty");
	return dq->data[(dq->front + 1) % MAX]; //front ���� ��ġ�� �ִ� �� ��ȯ, front ��ġ�� �״��
}
element del_rear(DequeType* dq) {
	if (is_empty(dq))error("deque is empty");
	int prev = dq->rear; //������ rear��ġ �ӽ� ����
	dq->rear = (dq->rear - 1 + MAX) % MAX; //rear�� ���ҽ��� ���ο� rear��.
	return dq->data[prev]; //�� ��ȯ
}
element del_front(DequeType* dq) {
	if (is_empty(dq))error("deque is empty");
	dq->front = (dq->front + 1) % MAX; //front�� ������Ŵ
	return dq->data[dq->front]; //������ front��ġ�� �ִ� �� ��ȯ
}
void print_deque(DequeType* dq) {
	printf("Deque(front:%d, rear:%d) = ", dq->front, dq->rear);
	if (!is_empty(dq)) {
		int i = dq->front;
		do {
			i = (i + 1) % MAX;
			printf("%3d  |", dq->data[i]);
			if (i == dq->rear)break; //���� ����
		} while (i != dq->front); //front�� ���ƿ��� ����
		printf("\n");
	}
}
int main() {
	DequeType dq;
	init(&dq);
	int element;

	printf("<front>�� ������ �߰�\n");
	for (int i = 0; i < 3; i++) {
		printf("���� �Է�: ");
		scanf_s("%d", &element);
		add_front(&dq, element);
		print_deque(&dq);
	}
	printf("\n<rear���� ������ ��������>\n");
	for (int i = 0; i < 4; i++) {
		printf("%3d\n", del_rear(&dq));
		print_deque(&dq);
	}
	return 0;
}