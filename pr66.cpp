/* 10���� �ǽ� 1 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 200

typedef struct {
	int key;
}element;
typedef struct {
	element heap[MAX]; //heap�� �迭�� ����(index�� 1����)
	int heap_size; //heap�� ũ�� ���� ����
}HeapType;

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}
void init(HeapType* h) {
	h->heap_size = 0;
}
void insert_max_heap(HeapType* h, element item) { //max heap�� ��� �߰�
	int i;
	i = ++(h->heap_size); //��� �߰� ����, �׸��� ���� ���� ��� �ε����� i�� ����

	/* i�� 1�̸�-- ù ���ϱ� �� x. && ���ο� ��� Ű�� �� �θ� ���ؼ� �� Ŭ ��쿡 �ݺ� */
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2]; //�߰��� ��� key������ ���� ���, �θ��带 i�� ����
		i /= 2; //�ε��� ���ο� ��ġ(�θ�)�� �̵�
	}
	h->heap[i] = item; //���� ������ ��ġ�� insert
}
element delete_max_heap(HeapType* h){
	int parent = 1, child = 2; // �� ��° ������ root ���� �� ����
	element item = h->heap[1]; // �����Ǵ� ���(���� �� ��ȯ)
	element temp = h->heap[h->heap_size--]; // ���� ��带 temp�� ����(��� ���� �� heap_size�� ����)
	
	while (child <= h->heap_size) { // �ִ� ���ܱ��� Ʈ���� �������鼭 �ڽĳ�� key���� temp key ��
		if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key)) // sibling�� ���� �� �� �� ū �� ã��
			child++; // sibling�� �񱳴�� ��尡 ��(subtree ����)
		if (temp.key >= h->heap[child].key) break; // �ڽ� ��庸�� �ű� ��� key�� ũ�� ��ġ Ȯ���Ǿ� �ݺ� ����
		
		h->heap[parent] = h->heap[child]; // �ڽ� ��� key�� �� ũ�� parent ��忡 child ��� ����
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp; // Ȯ����ġ(parent)�� �űԳ�� insert
	return item;

}
void print_heap(HeapType* h) {
	for (int i = 1; i <= h->heap_size; i++) { printf("%d ", h->heap[i]); }
	printf("\n");
}
int main() {
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 }, e4, e5, e6;
	HeapType* heap = create();
	init(heap); //�� !!!
	
	insert_max_heap(heap, e1); print_heap(heap);
	insert_max_heap(heap, e2); print_heap(heap);
	insert_max_heap(heap, e3); print_heap(heap);

	delete_max_heap(heap); print_heap(heap);
	delete_max_heap(heap); print_heap(heap);
	delete_max_heap(heap); print_heap(heap);

	free(heap);
	return 0;
}