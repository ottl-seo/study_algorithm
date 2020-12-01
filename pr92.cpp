/* LPT (Longest Processing Time first) */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 8
#define MAX 100

typedef struct element {
	int id; //��ȣ (�� ����)
	int avail; //���� �ð�
}element;
typedef struct HeapType {
	element heap[MAX];
	int heap_size;
}HeapType;

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType)); //����
}
void init(HeapType* h) { //heap �ʱ�ȭ �Լ�
	h->heap_size = 0; //�̰͸� ���ָ� ok	
}
void insert_min_heap(HeapType* h, element item) {
	int i = ++h->heap_size;
	while ((i != 1) && (item.avail < h->heap[i / 2].avail)) {
		h->heap[i] = h->heap[i / 2]; //�θ� ����
		i /= 2;
	}
	h->heap[i] = item; //���� ������ ��ġ�� ���ο� ��带 ����
}
element delete_min_heap(HeapType* h) {
	int parent = 1, child = 2;
	element item = h->heap[1];
	element temp = h->heap[h->heap_size--];
	
	while (child <= h->heap_size) {
	/* 1 */
		if (child < h->heap_size && (h->heap[child].avail > h->heap[child + 1].avail))child++; //sibling üũ- �� ���� �� ã��
	/* 2 */
		if (temp.avail < h->heap[child].avail)break; //min heap�̴ϱ� temp�� �� ���� ���-
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
	int jobs[JOBS] = { 8,7,6,5,3,2,1 }; //�۾��� ���ĵǾ��ִٰ� ����
	element m = { 0,0 }; //machine�� id, avail time.
	HeapType* h;
	h = create();
	init(h);

	for (int i = 0; i < MACHINES; i++) { //�ӽ� ���� �ʱ�ȭ
		m.id = i + 1;
		m.avail = 0;
		insert_min_heap(h, m);
	}
	for (int i = 0; i < JOBS; i++) {
		m = delete_min_heap(h);
		printf("JOB %d�� MACHINE %d�� �Ҵ� (%d - %d)\n", i, m.id, m.avail, (m.avail+jobs[i]-1));
		m.avail += jobs[i]; // job ����ð���ŭ avail time����
		insert_min_heap(h, m); //�ش� �ӽ� �ٽ� insert
	}
	return 0;
}
