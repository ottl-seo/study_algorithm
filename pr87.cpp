/* max heap 복습 */
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct element {
	int key; //
}element;
typedef struct HeapType {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}
void init(HeapType* h) {
	h->heap_size = 0;
}
void insert_max_heap(HeapType* h, element item) { /* 1)말단노드에 추가 - 2)upheap */
	int i;
	i = ++(h->heap_size); //size 먼저 ++
	while ((i != 1) && (item.key > h->heap[i / 2].key)) { //item의 크기가 부모보다 클 경우,
		h->heap[i] = h->heap[i / 2]; // 부모노드를 내림
		i /= 2; //기존 부모가 있던 위치로 가서 반복. item.key가 적절한 자리 찾을 때까지
	}
	h->heap[i] = item; //최종 결정된 위치에 insert
}
element delete_max_heap(HeapType* h) {
	
	int parent = 1, child = 2;
	element item = h->heap[1]; // 루트 노드 (삭제 예정)
	element temp = h->heap[h->heap_size--]; //말단 노드

	while (child <= h->heap_size) { //child가 
		/* sibling 중에 더 큰거 찾기 */
		if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key)) 
			child++;
		if (temp.key >= h->heap[child].key)break; //자식노드보다 신규노드key가 더 크면 break

		h->heap[parent] = h->heap[child]; //자식노드key가 더 크면 parent노드에 child노드 복사
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp; //확정된 위치(parent)에 신규노드 insert
	return item;
}
void print_max_heap(HeapType* h) {
	for (int i = 0; i < h->heap_size; i++)
		printf("%d ", h->heap[i+1].key); //주의-- heap은 인덱스 1부터 시작
	printf("\n");
}
int main() {
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 }, e4, e5, e6;
	HeapType* heap = create();
	init(heap);

	insert_max_heap(heap, e1); print_max_heap(heap);
	insert_max_heap(heap, e2); print_max_heap(heap);
	insert_max_heap(heap, e3); print_max_heap(heap);

	e4= delete_max_heap(heap); print_max_heap(heap);
	e5 = delete_max_heap(heap); print_max_heap(heap);
	e6 = delete_max_heap(heap); print_max_heap(heap);

	free(heap);
	return 0;
}