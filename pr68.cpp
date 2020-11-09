/* min heap */
#include <stdio.h>
#include <stdlib.h>
#define MAX 200

typedef struct {
	int key;
}element;
typedef struct {
	element heap[MAX];
	int heap_size;
}HeapType;

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}
void init(HeapType* h) {
	h->heap_size = 0; // 초기화
}
void insert_min_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size); //최대 개수 추가하고 마지막 노드에 일단 대입
	/*upheap*/
	while ((i != 1) && (item.key < h->heap[i/2].key)) { // [i/2]번째랑 비교해준다는 것!!!!!
		h->heap[i] = h->heap[i / 2];// 부모노드를 자식으로 내림
		i /= 2; //인덱스를 새로운 부모로 이동
	}
	h->heap[i] = item; //최종 결정된 위치에 insert
}
element delete_min_heap(HeapType* h) {
	int parent = 1, child = 2;
	element item = h->heap[1];
	element temp = h->heap[h->heap_size--];

	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child].key > h->heap[child + 1].key))
			child++; //sibling으로 자리를 옮겨준다
		if (temp.key <= h->heap[child].key)	break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp; //확정 위치 parent에 신규노드 insert
	return item;
}
void print_heap(HeapType* h) {
	for (int i = 1; i <= h->heap_size; i++)
		printf("%d ", h->heap[i].key);
	printf("\n");
}
int main() {
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 }, e4, e5, e6;
	HeapType* heap = create();
	init(heap); //꼭 !!!

	insert_min_heap(heap, e1); print_heap(heap);
	insert_min_heap(heap, e2); print_heap(heap);
	insert_min_heap(heap, e3); print_heap(heap);

	delete_min_heap(heap); print_heap(heap);
	delete_min_heap(heap); print_heap(heap);
	delete_min_heap(heap); print_heap(heap);

	free(heap);
	return 0;
}