#include <stdio.h>
#include <stdlib.h>

typedef struct dListNode {
	int num;
	dListNode* llink;
	dListNode* rlink;
}dListNode;
typedef struct dListType {
	dListNode* head;
	int size; //����Ʈ�� ũ��
}dListType;

void printInfo();
void error(const char* message);
dListNode* create(); //����
void insert_last(dListNode* head, int num); // �������� �� �߰��ϴ� �Լ�
void print_dlist(dListNode* head); //����Ʈ ��� �Լ�
void print_reverse(dListNode* head); //���� ��� �Լ�

/* ------------------ main -----------------*/
int main() {
	int input; //�Է°�
	dListNode* head = create(); //���ο� ����Ʈ ����
	
	printInfo(); //���� ���
	printf("Input data in dual linkedlist <0 to quit>\n");
	scanf_s("%d", &input);
	
	while (input != 0) {
		insert_last(head, input); //�� �߰�
		scanf_s("%d", &input);
	} //input���� 0�� ������ �Է� ����

	print_dlist(head); //����Ʈ ���
	printf("\nPrint the list in reverse order\n"); //���� ���
	print_reverse(head);

	free(head);
	return 0;
}
/* ---------------- func def -----------------*/
void error(const char* message) {
	fprintf(stderr, message);
	exit(1);
}
dListNode* create() { //����
	dListNode* head = (dListNode*)malloc(sizeof(dListNode)); //��� ���
	head->llink = head->rlink = head; //��� ��� �ʱ�ȭ

	return head; //�ʱ�ȭ�� head ��ȯ
}
void insert_last(dListNode* head, int num) { // �������� �� �߰��ϴ� �Լ�
	dListNode* p = (dListNode*)malloc(sizeof(dListNode)); //���ο� ��� ����
	p->num = num;

	p->llink = head->llink;
	p->rlink = head;
	head->llink->rlink = p;
	head->llink = p;
}
void print_dlist(dListNode* head) { //����Ʈ ��� �Լ�
	dListNode* p = (dListNode*)malloc(sizeof(dListNode)); //���ο� ��� ����
	for (p = head->rlink; p != head->llink; p = p->rlink)
		printf("  %d  <->", p->num);
	printf("  %d", p->num);
}
void print_reverse(dListNode* head) { //���� ��� �Լ�
	dListNode* p = (dListNode*)malloc(sizeof(dListNode)); //���ο� ��� ����
	for (p = head->llink; p != head->rlink; p = p->llink)
		printf("  %d  <->", p->num);
	printf("  %d", p->num);
}

void printInfo(void) {
	printf("====================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971063\n");
	printf("����: ������\n");
	printf("====================\n");
}