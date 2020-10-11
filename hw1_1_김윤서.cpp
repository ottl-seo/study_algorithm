#include <stdio.h>
#include <stdlib.h>
#include <math.h> //pow �Լ� ����ϱ� ���� ���

typedef struct ListNode {
	int coef; //���
	int expon; //����(x^)
	struct ListNode* link; // ���
}ListNode;
typedef struct ListType { //���׽��� ���� ��Ÿ���� ���
	int size; //���׽��� �� ����
	ListNode* head;
	ListNode* tail;
}ListType;

void printInfo();
void error(const char* message);
void init(ListNode* p); //��� �� �� �ʱ�ȭ- �� ���� �߰��� ������ �ʱ�ȭ�ؼ� ���� ����
ListType* create(); //ListType ��� ���� (���׽� ���� �ʱ�ȭ)
void insert_last(ListType* plist, int coef, int expon); //���ο� �� �߰�
void print_poly(ListType* plist); //���׽� ���
int poly_result(ListType* plist, int x); // x�� �־��� �� �Լ��� ����ؼ� ��ȯ

/* ---------------- main ----------------- */
int main() {
	printInfo(); //���� ���
	int coef, expon; //�Է¹��� ���, ����
	int x; //�Է¹��� x ��
	ListType* poly = create(); //���ο� poly ����

	printf("Input coef and exponent of polynomial <��������: exponent�� 0���� �Է�>\n");
	scanf_s("%d %d", &coef, &expon);
	insert_last(poly, coef, expon); // ���׽Ŀ� 

	while (expon != 0) { //��������(expon�� 0) �Է� ������ �ݺ�
		scanf_s("%d %d", &coef, &expon);
		insert_last(poly, coef, expon); //�� �߰�
	}
	printf("\n< Polynomial >\n"); //���׽� ���
	print_poly(poly);
	
	printf("\nInput the value x: ");
	scanf_s("%d", &x);
	printf("\nResult of polynomial with x: %d\n", poly_result(poly, x)); //x�� �־ ����ؼ� ����� ���
	
	free(poly); //�����Ҵ��� poly Ǯ����
	return 0;
}
/* ---------------- function def ----------------- */
void error(const char* message) {
	fprintf(stderr, message);
	exit(1);
}
ListType* create() { //ListType ��� ���� (���׽� ���� �ʱ�ȭ)
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->head = NULL;
	plist->tail = NULL;
	plist->size = 0; //���׽� ���� �ʱ�ȭ
	return plist;
}
void insert_last(ListType* plist, int coef, int expon) { //���ο� �� �߰�
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //�߰��� ��
	if (p == NULL) { //�޸� �Ҵ� ���� ��
		error("���� �޸� �Ҵ� ����");
		exit(1);
	}
	p->coef = coef;
	p->expon = expon; //����� ������ �־��ش�
	p->link = NULL;

	if (plist->size == 0) { plist->head = plist->tail = p; } //ù ���� ���
	else { 
		plist->tail->link = p; //������ �װ� ����
		plist->tail = p; //p�� ������������ ����
	}
	plist->size++; //������ ++
}
void print_poly(ListType* plist) {
	ListNode* p = NULL;
	for (p = plist->head; p != plist->tail;p=p->link) //�������� ������ ��� ���� �湮�ϵ���
		printf("%dx^%d + ", p->coef, p->expon);
	printf("%dx^%d\n", p->coef, p->expon); //������ ���� +���� ���
}
int poly_result(ListType* plist, int x) {
	int result = 0;
	ListNode* p = plist->head;
	for (int i = 0; i < plist->size; i++) {
		result += (int)pow((double)x, (double)(p->expon)) * (p->coef); //���� ������ִ� pow�Լ� �̿�
		p = p->link; //���������� �̵�
	}
	return result;
}

void printInfo(void) {
	printf("====================\n");
	printf("�а�: ���̹���������\n");
	printf("�й�: 1971063\n");
	printf("����: ������\n");
	printf("====================\n");
}