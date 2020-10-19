/* week4. ���Ḯ��Ʈ�� ������ ���׽� ���� */
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int coef; //���
	int expon; //����
	ListNode* link; //���� ���Ḯ��Ʈ �ּ�
}ListNode;

typedef struct ListType {
	ListNode* head; //ó�� ��� �ּ�
	ListNode* tail; // ������ ��� �ּ�
	int size; //���׽��� �׼�
}ListType;

void error(const char* message);
ListType* create(); // ��� ���� �� �ʱ�ȭ���� �ϴ� �Լ�
void insert_last(ListType* plist, int coef, int expon);
void print_poly(ListType* plist);
void poly_add(ListType* list1, ListType* list2, ListType* result);

int main() {
	ListType* list1, * list2, * list3;

	list1 = create();
	list2 = create();
	list3 = create();

	insert_last(list1, 3, 12); // 3x^12
	insert_last(list1, 5, 8); // 5x^8
	insert_last(list1, 3, 3); // 3x^3
	insert_last(list1, 1, 0); // 1

	insert_last(list2, 8, 12); // 8x^12
	insert_last(list2, -3, 10); // -3x^10
	insert_last(list2, 10, 6); // 10x^6

	printf("< Poly 1 >\n");
	print_poly(list1);

	printf("< Poly 2 >\n");
	print_poly(list2);

	poly_add(list1, list2, list3);
	printf("< Result >\n");
	print_poly(list3);

	free(list1); free(list2); free(list3);
	return 0;
}
void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListType* create() { // ��� ���� �� �ʱ�ȭ���� �ϴ� �Լ�
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->head = plist->tail = NULL;
	plist->size = 0;
	return plist;
}
void insert_last(ListType* plist, int coef, int expon) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->coef = coef;
	p->expon = expon;
	p->link = NULL;
	if (plist->size == 0) { //�� ����Ʈ�� ���- ù ����� ���
		plist->head = plist->tail = p;
	}
	else {
		plist->tail->link = p;
		plist->tail = p;
	}
	plist->size++; //���׽� �� ���� �ϳ� ����
}
void print_poly(ListType* plist) {
	ListNode* p = NULL;
	for (p = plist->head; p != plist->tail; p=p->link)
		printf("%dx^%d + ", p->coef, p->expon);
	printf("%dx^%d \n", plist->tail->coef, plist->tail->expon);
}
void poly_add(ListType* list1, ListType* list2, ListType* result) {
	ListNode* p1, * p2;
	p1 = list1->head; //ù��° ���׽� ���� �ּ�
	p2 = list2->head; //�ι�° ���׽� ���� �ּ�
	int sum;
	while (p1 && p2) { //�� ���׽� ��ο� ���� �����ִ� ����.
		if (p1->expon > p2->expon) {
			insert_last(result, p1->coef, p1->expon);
			p1 = p1->link;
		}
		else if (p1->expon == p2->expon) {
			insert_last(result, p1->coef + p2->coef, p1->expon);
			p1 = p1->link;
			p2 = p2->link;
		}
		else {
			insert_last(result, p2->coef, p2->expon);
			p2 = p2->link;
		}
	}
	while (p1) { //ù��° ���׽Ŀ� ���� ���� ����������
		insert_last(result, p1->coef, p1->expon); //���� ���� ��� �״�� ����(while)
		p1 = p1->link;
	}
	while (p2) {
		insert_last(result, p2->coef, p2->expon); //���� ���� ��� �״�� ����(while)
		p2 = p2->link;
	}
}
