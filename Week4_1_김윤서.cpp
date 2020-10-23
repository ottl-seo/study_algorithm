#include <stdio.h>
#include <stdlib.h>

typedef int element; //int Ÿ���� element �ڷ��� ����
typedef struct ListNode {
	element num; //����ڰ� �Է��ϴ� ����
	ListNode* link; //��� ���ῡ ����� link
}ListNode;
typedef struct ListType { //����Ʈ�� ���� �����ϴ� ����ü- ������ġ, ������ġ, ����Ʈ ũ��...
	ListNode* head;
	ListNode* tail;
	int size;
};

void printName();
void error(const char* message);
ListType* create(void);
void printList(ListType* plist); //����Ʈ ��� �Լ�
void insert_last(ListType* plist, int value); //����Ʈ �������� insert�ϴ� �Լ�
int search_MAX(ListType* plist);
int search_MIN(ListType* plist);

//-------------------- main ----------------------
int main() {
	printName();
	int input; //����ڰ� ���� �Է�
	ListType* intList;
	intList = create();

	while (true) //���ѹݺ�, input�� 0�̸� ����
	{
		printf("Input an integer to insert <0 to quit>: ");
		scanf_s("%d", &input);
		if (input == 0) { break; } //�Է��� 0�� ��� �ݺ��� ����������
		else { insert_last(intList, input); } //intList �������� input���� ����
	}
	printf("\n<List>\n");
	printList(intList); //����Ʈ ���

	printf("\nMax: %d\n", search_MAX(intList)); //max
	printf("\nMin: %d\n", search_MIN(intList)); //min

	free(intList);
	return 0;
}
//-------------------- �Լ� ���� Area ----------------------
void error(const char* message) { //���� �޽���
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListType* create(void) { // ListType ��� ���� (���׽� ���� ������ ���)
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->head = NULL;
	plist->tail = NULL;
	plist->size = 0;
	return plist; //�����ϰ� �ʱ�ȭ�ؼ� ��ȯ�ϴ� �Լ���
}

void insert_last(ListType* plist, int value) { //����Ʈ �������� insert�ϴ� �Լ�
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //����ü p ����(������ ����ü)
	
	if (p == NULL) { //�޸� �Ҵ� ���� ��
		error("���� �޸� �Ҵ� ����");
		exit(1);
	}
	p->num = value; //�ϴ� p�� �� ����
	p->link = NULL; //��ũ�� �ϴ� NULL��.

	if (plist->size == 0) { //����Ʈ�� �ƹ��͵� ������
		/* head�� p �����ϴ� ��� */
		plist->head = plist->tail = p; //OK
	}
	else {
		plist->tail->link = p; //���� OK
		plist->tail = p; // ������ ���� ������ �� ��� �ּ�(p)�� ����
	}
	plist->size++; //�� ���� ���� �ϳ� �������ֱ�++
}
void printList(ListType* plist) {  //����Ʈ ��� �Լ�
	ListNode* p = plist->head;
	for (int i=0; i< plist->size; i++) { //head���� �����ؼ� ��(NULL���ö�)���� �ݺ�
		printf("%d  ", p->num);
		p = p->link;
	}
}
int search_MAX(ListType* plist) {
	int max = plist->head->num; //�ִ��� �� ó�� ������ ����
	for (ListNode* p = plist->head; p != NULL; p = p->link) { //head���� �����ؼ� ��(NULL���ö�)���� �ݺ�
		if ((p->num) > max) //max���� ���� ����� num�� �� ũ�ٸ�
			max = p->num; // p->num�� �ִ����� ����
		else
			continue; //�ƴϸ� ���������� �̵�
	}
	return max;
}
int search_MIN(ListType* plist) {
	int min = plist->head->num; //�ּڰ��� �� ó�� ������ ����
	for (ListNode* p = plist->head; p != NULL; p = p->link) { //head���� �����ؼ� tail���� �ݺ�
		if ((p->num) < min) //min���� ���� ����� num�� �� �۴ٸ�
			min = p->num; // p->num�� �ּڰ����� ����
		else
			continue; //�ƴϸ� ���������� �̵�
	}
	return min;
}


void printName(void) {
	printf("====================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971063\n");
	printf("����: ������\n");
	printf("====================\n");
}