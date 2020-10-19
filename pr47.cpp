/* week4. 연결리스트로 구현한 다항식 덧셈 */
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int coef; //계수
	int expon; //차수
	ListNode* link; //다음 연결리스트 주소
}ListNode;

typedef struct ListType {
	ListNode* head; //처음 노드 주소
	ListNode* tail; // 마지막 노드 주소
	int size; //다항식의 항수
}ListType;

void error(const char* message);
ListType* create(); // 노드 생성 후 초기화까지 하는 함수
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
ListType* create() { // 노드 생성 후 초기화까지 하는 함수
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
	if (plist->size == 0) { //빈 리스트일 경우- 첫 노드일 경우
		plist->head = plist->tail = p;
	}
	else {
		plist->tail->link = p;
		plist->tail = p;
	}
	plist->size++; //다항식 항 개수 하나 증가
}
void print_poly(ListType* plist) {
	ListNode* p = NULL;
	for (p = plist->head; p != plist->tail; p=p->link)
		printf("%dx^%d + ", p->coef, p->expon);
	printf("%dx^%d \n", plist->tail->coef, plist->tail->expon);
}
void poly_add(ListType* list1, ListType* list2, ListType* result) {
	ListNode* p1, * p2;
	p1 = list1->head; //첫번째 다항식 시작 주소
	p2 = list2->head; //두번째 다항식 시작 주소
	int sum;
	while (p1 && p2) { //두 다항식 모두에 항이 남아있는 동안.
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
	while (p1) { //첫번째 다항식에 아직 항이 남아있으면
		insert_last(result, p1->coef, p1->expon); //남은 항을 모두 그대로 복사(while)
		p1 = p1->link;
	}
	while (p2) {
		insert_last(result, p2->coef, p2->expon); //남은 항을 모두 그대로 복사(while)
		p2 = p2->link;
	}
}
