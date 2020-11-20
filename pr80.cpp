#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define TRUE 1
#define FALSE 0
#define INF 1000 // 무한대 표현

#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t)) //왼쪽으로 하나씩 밀어주는 매크로

int vertex[MAX]; //vertex 배열
int parent[MAX]; //부모 vertex값 저장 배열

typedef struct Edge { // Er 역할 (edge 구조 --꼭 구조체 안해도 됨!)
	int start, end, weight;
}Edge;

typedef struct GraphType {
	int n; //edge 개수
	int vertexCnt; //vertex 개수
	struct Edge edges[2 * MAX]; //edge 수는 vertex 수의 두 배 (MST이므로)
}GraphType;

/*================= Quick Sort =================*/ //나중에 설명..
int partition(Edge edges[], int left, int right)
{
	Edge pivot, temp;
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
void quick_sort(Edge edges[], int left, int right)
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
int set_find(int curr) { //curr가 속한 집합을 찾아 반환 (루트 찾기)
	if (parent[curr] == -1)return curr; //curr가 루트일 경우

	while (parent[curr] != -1) curr = parent[curr]; //parent가 루트일 때까지 반복
	return curr;
}
void set_union(int a, int b) { //2개의 노드 집합을 하나로 합치기
	int root1 = set_find(a); //a의 루트 찾기
	int root2 = set_find(b); //b의 루트
	if (root1 != root2) //다른 루트이면,
		parent[root1] = root2; //두 집합을 하나로 합친다 (root2를 새로운 루트로)
}

/*================= Graph drawing =================*/
void graph_init(GraphType* g) {
	g->n = 0; //edge 수 0
	g->vertexCnt = 0; //vertex 수 0
	for (int i = 0; i < 2 * MAX; i++) { //모든 edge를 초기화...
		g->edges[i].start = 0;
		g->edges[i].end = 0;
		g->edges[i].weight = INF; //weight가 작은 값을 찾아야 하므로 초기값을 무한대로 설정
	}
}
void insert_edge(GraphType* g, int start, int end, int w) { //start와 end 두 vertex를 잇는 edge 생성
	g->edges[g->n].start = start;
	g->edges[g->n].end = end;
	g->edges[g->n].weight = w; //weight를 지정해줌
	g->n++; //노드 개수 ++
}

/*================= Kruskal =================*/
void kruskal(GraphType* g) {
	int edge_accepted = 0; // 현재까지 선택된 edge의 수(= Er의 원소 개수)
	int uset, vset; //vertex u와 v의 집합 번호(root vertex의 번호)
	Edge Er; //MST의 edge 집합 Er

	set_init(g->n); // set 초기화
	quick_sort(g->edges, 0, g->n - 1); //weight값을 가지고 edge를 Quick Sort
	printf("\n<Sort 결과>\n");
	for (int i = 0; i < g->n; i++) {
		printf("%2d -%2d : %2d\n", g->edges[i].start, g->edges[i].end, g->edges[i].weight);
	}
	printf("\n<Kruskal 결과>\n");
	int i = 0;
	while (edge_accepted < (g->vertexCnt - 1)) {
		//spanning tree에 포함된 edge (=Er 개수)가 (vertex-1)보다 작을 동안 반복
		
		Er = g->edges[i]; //0번 edge부터 시작
		uset = set_find(Er.start); //start vertex의 루트 찾기
		vset = set_find(Er.end); // end vertex의 루트 찾기
		
		if (uset != vset) { //서로 다른 집합이면
			printf("Edge (%d, %d) %d \n", Er.start, Er.end, Er.weight);
			edge_accepted++;
			set_union(uset, vset); //두 집합 합치기
		}
		i++;
	}
}
void vertex_cnt(GraphType* g) { //vertex 수 count
	int cnt = 0;
	for (int i = 0; i < g->n; i++) {
		if (vertex[g->edges[i].start] == 0) { //아직 count 안 된 vertex 번호
			vertex[g->edges[i].start] = 1;
			cnt++;
		}
		if (vertex[g->edges[i].end] == 0) { //아직 count 안된 vertex 번호 있으면
			vertex[g->edges[i].end] = 1;
			cnt++;
		}
	}
	g->vertexCnt = cnt; //vertex 수 count 해서 대입
}

/* ======================== main ========================== */
int main() {
	GraphType* g = (GraphType*)malloc(sizeof(GraphType));
	graph_init(g);

	insert_edge(g, 0, 1, 29); //start,end,weight
	insert_edge(g, 1, 2, 16);
	insert_edge(g, 2, 3, 12);
	insert_edge(g, 3, 4, 22);
	insert_edge(g, 4, 5, 27);
	insert_edge(g, 5, 0, 10);
	insert_edge(g, 6, 1, 15);
	insert_edge(g, 6, 3, 18);
	insert_edge(g, 6, 4, 25);
	
	vertex_cnt(g); //vertex 수를 count 해서 g->vertexCnt에 저장
	kruskal(g);
	
	free(g);
	return 0;
}
