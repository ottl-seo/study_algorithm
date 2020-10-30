/* tree_pr4.레벨 순회 코드 
	- 안 돌아감 왜???? */
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct TreeNode {
	int data;
	TreeNode* left, * right;
}TreeNode;

typedef TreeNode* element;
typedef struct QueueType {
	element data[MAX];
	int front, rear;
}QueueType;

void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
bool is_full(QueueType* q) {
	return ((q->rear + 1) % MAX == q->front);
}
bool is_empty(QueueType* q) {
	return (q->front == q->rear == 0);
}
void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}
void enqueue(QueueType* q, element item) {
	if (is_full(q))error("Queue is full");
	q->rear = (q->rear + 1) % MAX;
	q->data[q->rear] = item;
}
element dequeue(QueueType* q) {
	if (is_empty(q))error("Queue is empty");
	q->front = (q->front + 1) % MAX;
	return q->data[q->front];
}
void level_order(TreeNode* ptr) { //tree노드 ptr을 큐에 넣어 레벨 순회
	QueueType q;
	init_queue(&q);
	if (ptr == NULL)return;
	enqueue(&q, ptr); //root값을 enqueue
	while (!is_empty(&q)) { //q에 데이터가 있는 동안 dequeue
		ptr = dequeue(&q);
		printf("[%d]", ptr->data);
		if (ptr->left)enqueue(&q, ptr->left); //dequeue 하고 나서 하위 두개 child를 enqueue
		if (ptr->right)enqueue(&q, ptr->right);
	}
}
TreeNode n1 = { 1,NULL,NULL };
TreeNode n2 = { 2,&n1,NULL };
TreeNode n3 = { 3,NULL,NULL };
TreeNode n4 = { 4,NULL,NULL };
TreeNode n5 = { 5,&n3,&n4 };
TreeNode n6 = { 6,&n2,&n5 };
TreeNode* root = &n6;

int main() {
	
	printf("레벨 순회\n");
	level_order(root);
	printf("\n");

	return 0;
}
