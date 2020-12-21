/* heap 코드나 복습해보기 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 200

typedef struct element {
	int key;
}element;
typedef struct HeapType {
	element heap[MAX];
	int heap_size;
}HeapType;

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}
void init(HeapType* h) {
	h->heap_size = 0;
}
void insert_max_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item; // insert 까지만 해야겠다 피곤
}
int main() {
	return 0;
}
