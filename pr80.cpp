
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define TRUE 1
#define FALSE 0
#define INF 1000 // 무한대 표현

#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))

int vertex[MAX]; //vertex 배열
int parent[MAX]; //부모 vertex값 저장 배열

struct Edge { //edge 구조
	int start, end, weight;
};
typedef struct GraphType {
	int n; //edge 개수
	int vertexCnt; //vertex 개수
	struct Edge edges[2 * MAX]; //edge 수는 vertex 수의 두 배 (MST이므로)
}GraphType;

/*================= Quick Sort =================*/
int partition(struct Edge edges[], int left, int right)
{
	struct Edge pivot, temp;
	int low, high;
	low = left;
	high = right + 1;
	pivot.weight = edges[left].weight;
	do {
		do
			low++;
		while (low <= right && edges[low].weight < pivot.weight);
		do
			high--;
		while (high >= left && edges[high].weight > pivot.weight);
		if (low < high) SWAP(edges[low], edges[high], temp);
	} while (low < high);
	SWAP(edges[left], edges[high], temp);
	return high;
}
void quick_sort(struct Edge edges[], int left, int right)
{
	if (left < right) {
		int q = partition(edges, left, right);
		quick_sort(edges, left, q - 1);
		quick_sort(edges, q + 1, right);
	}
}

/*================= Union-Find =================*/
void set_init(int n) {
	for (int i = 0; i < n; i++)
		parent[i] = -1; //초기화
}
int set_find(int curr) { //curr가 속한 집합을 찾아 반환
	if (parent[curr] == -1)return curr;
	while (parent[curr] != -1)curr = parent[curr];
	return curr;
}
