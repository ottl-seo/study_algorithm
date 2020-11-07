/* 10주차 실습 1 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 200

typedef struct {
	int key;
}element;
typedef struct {
	element heap[MAX]; //heap은 배열로 구현(index는 1부터)
	int heap_size; //heap의 크기 정보 저장
}HeapType;

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}
void init(HeapType* h) {
	h->heap_size = 0;
}
void insert_max_heap(HeapType* h, element item) { //max heap에 노드 추가
	int i;
	i = ++(h->heap_size); //노드 추가 먼저, 그리고 가장 말단 노드 인덱스를 i에 대입

	/* i가 1이면-- 첫 노드니까 비교 x. && 새로운 노드 키랑 그 부모를 비교해서 더 클 경우에 반복 */
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2]; //추가된 노드 key값보다 작은 경우, 부모노드를 i로 내림
		i /= 2; //인덱스 새로운 위치(부모)로 이동
	}
	h->heap[i] = item; //최종 결정된 위치에 insert
}
element delete_max_heap(HeapType* h){
	int parent = 1, child = 2; // 두 번째 노드부터 root 노드와 비교 시작
	element item = h->heap[1]; // 삭제되는 노드(삭제 후 반환)
	element temp = h->heap[h->heap_size--]; // 말단 노드를 temp에 대입(노드 삭제 후 heap_size가 감소)
	
	while (child <= h->heap_size) { // 최대 말단까지 트리를 내려가면서 자식노드 key값과 temp key 비교
		if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key)) // sibling이 있을 때 둘 중 큰 값 찾기
			child++; // sibling이 비교대상 노드가 됨(subtree 선택)
		if (temp.key >= h->heap[child].key) break; // 자식 노드보다 신규 노드 key가 크면 위치 확정되어 반복 종료
		
		h->heap[parent] = h->heap[child]; // 자식 노드 key가 더 크면 parent 노드에 child 노드 복사
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp; // 확정위치(parent)에 신규노드 insert
	return item;

}
void print_heap(HeapType* h) {
	for (int i = 1; i <= h->heap_size; i++) { printf("%d ", h->heap[i]); }
	printf("\n");
}
int main() {
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 }, e4, e5, e6;
	HeapType* heap = create();
	init(heap); //꼭 !!!
	
	insert_max_heap(heap, e1); print_heap(heap);
	insert_max_heap(heap, e2); print_heap(heap);
	insert_max_heap(heap, e3); print_heap(heap);

	delete_max_heap(heap); print_heap(heap);
	delete_max_heap(heap); print_heap(heap);
	delete_max_heap(heap); print_heap(heap);

	free(heap);
	return 0;
}