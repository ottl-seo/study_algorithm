/* max heap ���� */
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
void insert_max_heap(HeapType* h, element item) { /* 1)���ܳ�忡 �߰� - 2)upheap */
	int i;
	i = ++(h->heap_size); //size ���� ++
	while ((i != 1) && (item.key > h->heap[i / 2].key)) { //item�� ũ�Ⱑ �θ𺸴� Ŭ ���,
		h->heap[i] = h->heap[i / 2]; // �θ��带 ����
		i /= 2; //���� �θ� �ִ� ��ġ�� ���� �ݺ�. item.key�� ������ �ڸ� ã�� ������
	}
	h->heap[i] = item; //���� ������ ��ġ�� insert
}
element delete_max_heap(HeapType* h) {
	
	int parent = 1, child = 2;
	element item = h->heap[1]; // ��Ʈ ��� (���� ����)
	element temp = h->heap[h->heap_size--]; //���� ���

	while (child <= h->heap_size) { //child�� 
		/* sibling �߿� �� ū�� ã�� */
		if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key)) 
			child++;
		if (temp.key >= h->heap[child].key)break; //�ڽĳ�庸�� �űԳ��key�� �� ũ�� break

		h->heap[parent] = h->heap[child]; //�ڽĳ��key�� �� ũ�� parent��忡 child��� ����
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp; //Ȯ���� ��ġ(parent)�� �űԳ�� insert
	return item;
}
void print_max_heap(HeapType* h) {
	for (int i = 0; i < h->heap_size; i++)
		printf("%d ", h->heap[i+1].key); //����-- heap�� �ε��� 1���� ����
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