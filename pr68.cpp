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
	h->heap_size = 0; // �ʱ�ȭ
}
void insert_min_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size); //�ִ� ���� �߰��ϰ� ������ ��忡 �ϴ� ����
	/*upheap*/
	while ((i != 1) && (item.key < h->heap[i/2].key)) { // [i/2]��°�� �����شٴ� ��!!!!!
		h->heap[i] = h->heap[i / 2];// �θ��带 �ڽ����� ����
		i /= 2; //�ε����� ���ο� �θ�� �̵�
	}
	h->heap[i] = item; //���� ������ ��ġ�� insert
}
element delete_min_heap(HeapType* h) {
	int parent = 1, child = 2;
	element item = h->heap[1];
	element temp = h->heap[h->heap_size--];

	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child].key > h->heap[child + 1].key))
			child++; //sibling���� �ڸ��� �Ű��ش�
		if (temp.key <= h->heap[child].key)	break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp; //Ȯ�� ��ġ parent�� �űԳ�� insert
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
	init(heap); //�� !!!

	insert_min_heap(heap, e1); print_heap(heap);
	insert_min_heap(heap, e2); print_heap(heap);
	insert_min_heap(heap, e3); print_heap(heap);

	delete_min_heap(heap); print_heap(heap);
	delete_min_heap(heap); print_heap(heap);
	delete_min_heap(heap); print_heap(heap);

	free(heap);
	return 0;
}