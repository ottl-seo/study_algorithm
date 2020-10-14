/* ���� 1-1. �迭 �̿��� ���� ť */
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX];
}QueueType;

void error(const char* message);
void init(QueueType* q); //queue �ʱ�ȭ
bool is_full(QueueType* q);
bool is_empty(QueueType* q);
void enqueue(QueueType* q, element item);
element dequeue(QueueType* q);
void print_queue(QueueType* q);

int main() {
	element item;
	QueueType q; //queue �����ϰ�, //�����Ҵ� �ؾ��ϳ�???
	init(&q); //�ʱ�ȭ
	enqueue(&q, 10); print_queue(&q);
	enqueue(&q, 20); print_queue(&q);
	enqueue(&q, 30); print_queue(&q);

	item = dequeue(&q); print_queue(&q);
	item = dequeue(&q); print_queue(&q);
	item = dequeue(&q); print_queue(&q);
	item = dequeue(&q); print_queue(&q);

	return 0;
}

/* �Լ� ������ ------------------ */
void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void init(QueueType* q) { //queue �ʱ�ȭ
	q->front = q->rear = -1; //���� ť�̹Ƿ� -1���� ����. ������ 0����, ���Ḯ��Ʈ�� NULL��.
}
bool is_full(QueueType* q) {
	return (q->rear == MAX - 1); //max������ 1 ������ rear�� ������ full
}
bool is_empty(QueueType* q) {
	return (q->rear == q->front); //rear�� front�� ���� ���
}
void enqueue(QueueType* q, element item) {
	if (is_full(q)) { error("queue Overflow"); return; }
	q->data[++q->rear] = item; //���� ����, ���� �� ����
}
element dequeue(QueueType* q) {
	if (is_empty(q)) { error("queue empty"); return -1; }
	else return q->data[q->front++];
}
void print_queue(QueueType* q) {
	for (int i = 0; i < MAX; i++) {
		if (i < q->front || i > q->rear)
			printf("	|");
		else { printf("%3d	|",q->data[i]); }
	}
	printf("\n");
}