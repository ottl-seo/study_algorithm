/* LPT (Longest Processing Time first) */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 8
#define MAX 100

typedef struct element {
	int id; //번호 (안 쓰임)
	int avail; //실행 시간
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
void insert_min_heap(HeapType* h, element item) {
	int i = ++h->heap_size;
	while ((i != 1) && (item.avail < h->heap[i / 2].avail)) {
		h->heap[i] = h->heap[i / 2]; //부모를 내림
		i /= 2;
	}
	h->heap[i] = item; //최종 결정된 위치에 새로운 노드를 삽입
}
element delete_min_heap(HeapType* h) {
	int parent = 1, child = 2;
	element item = h->heap[1];
	element temp = h->heap[h->heap_size--];
	
	while (child <= h->heap_size) {
	/* 1 */
		if (child < h->heap_size && (h->heap[child].avail > h->heap[child + 1].avail))child++; //sibling 체크- 더 작은 것 찾기
	/* 2 */
		if (temp.avail < h->heap[child].avail)break; //min heap이니까 temp가 더 작을 경우-
	/* 3 */
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

#define JOBS 7
#define MACHINES 3

int main() {
	int jobs[JOBS] = { 8,7,6,5,3,2,1 }; //작업은 정렬되어있다고 가정
	element m = { 0,0 }; //machine의 id, avail time.
	HeapType* h;
	h = create();
	init(h);

	for (int i = 0; i < MACHINES; i++) { //머신 전부 초기화
		m.id = i + 1;
		m.avail = 0;
		insert_min_heap(h, m);
	}
	for (int i = 0; i < JOBS; i++) {
		m = delete_min_heap(h);
		printf("JOB %d을 MACHINE %d에 할당 (%d - %d)\n", i, m.id, m.avail, (m.avail+jobs[i]-1));
		m.avail += jobs[i]; // job 수행시간만큼 avail time증가
		insert_min_heap(h, m); //해당 머신 다시 insert
	}
	return 0;
}
