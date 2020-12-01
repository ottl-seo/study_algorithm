/* heap Sort (week10) */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 8
#define MAX 100

typedef struct element {
	int key;
}element;
typedef struct HeapType {
	element heap[MAX];
	int heap_size;
}HeapType;

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType)); //생성
}
void init(HeapType* h) { //heap 초기화 함수
	h->heap_size = 0; //이것만 해주면 ok	
}
void insert_max_heap(HeapType* h, element item) {
	int i = ++h->heap_size; //말단 노드부터 item과 비교 시작
	while ((i != 1) && (item.key > h->heap[i / 2].key)) { // i의 부모와 item을 비교- item이 더 크다면
		h->heap[i] = h->heap[i/2]; //부모 노드를 "내림" (그리고 최종에서 부모에 item을 넣을거임)
		i /= 2; //인덱스 새로운 위치(부모)로 이동
	}
	h->heap[i] = item;
}
element delete_max_heap(HeapType* h) {
	int parent = 1, child = 2;
	element item = h->heap[1]; //삭제할 노드 (루트)
	element temp = h->heap[h->heap_size--]; //말단 노드

	while (child <= h->heap_size) {
		/* 1. sibling 중에 큰 값 찾기 */
		if (child < h->heap_size && (h->heap[child].key < h->heap[child + 1].key))
			child++;
		
		/* 2. temp가 child보다 커지면 break */
		if (temp.key>=h->heap[child].key) break;

		/* 3. parent에 값을 넣어주고 child는 다음 값으로. */
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}				//end of while

	/* 4. 확정위치(parent)에 신규노드(temp) insert */
	h->heap[parent] = temp;
	return item;
}
void heap_sort(element a[], int n) {
	int i;
	HeapType* h;
	h = create();
	init(h); // 새로운 heap을 하나 만들고 초기화한다

	for (i = 0; i < n; i++)
		insert_max_heap(h, a[i]); // max heap에 넣으면서 자동 정렬 (upheap)
	
	printf("< Before Sorting >\n");
	for (i = 1; i <= h->heap_size; i++)
		printf("%d ", h->heap[i]);
	
	for (i = (n - 1); i >= 0; i--)
		a[i] = delete_max_heap(h);

	free(h);
}
int main() {
	element list[SIZE] = { 23,56,11,9,56,99,27,34 };

	heap_sort(list, SIZE);
	printf("\n\n< Sorting Result >\n");
	for (int i = 0; i < SIZE; i++)
		printf("%d ", list[i].key);
	printf("\n");

	return 0;
}
