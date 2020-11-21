/* Prim의 MST 코드 */
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

typedef struct GraphType {
	int n; //정점의 개수
	int weight[MAX_VERTICES][MAX_VERTICES]; //vertex 정보를 행렬로 표현
}GraphType;

int selected[MAX_VERTICES]; //MST에 선택된 vertex의 집합
int dist[MAX_VERTICES]; //MST 내의 vertex에서 각 vertex까지의 거리...

int get_min_vertex(int n) { /* MST의 vertex로부터 가장 짧은 distance를 갖는 vertex 반환하는 함수 */
	int v, i;
	for (i = 0; i < n; i++) {
		if (!selected[i]) {
			v = i; //아직 선택 안 된 첫번째 vertex v 찾기
			break;
		}
	}
	for (i = 0; i < n; i++)
		if (!selected[i] && (dist[i] < dist[v]))v = i; //최솟값 찾기
	return v;
}
void prim(GraphType* g, int s) {
	int i, u, v;
	for (u = 0; u < g->n; u++)
		dist[u] = INF; //모든 distance가 무한대 --초기화
	dist[s] = 0; //0번 노드부터 시작

	printf("<Prim MST 결과>\n");
	for (i = 0; i < g->n; i++) {
		u = get_min_vertex(g->n);
		selected[u] = TRUE; // MST로부터 distance 가장 짧은 vertex u를 MST에 추가
		
		if (dist[u] == INF)return; //가장 짧은 거리가 무한대면 오류!
		printf("vertex %d\n", u);
		for (v = 0; v < g->n; v++) {
			if (!selected[v] && g->weight[u][v] < dist[v])
				dist[v] = g->weight[u][v];
		}
	}
}
int main() {
	GraphType g = { 7, //vertex수 = 7
		{
		{0,29,INF,INF,INF,10,INF}, //직접 연결된 edge 없을 때
		{29,0,16,INF,INF,INF,15},
		{INF,16,0,12,INF,INF,INF},
		{INF,INF,12,0,22,INF,18},
		{INF,INF,INF,22,0,27,25},
		{10,INF,INF,INF,27,0,INF},
		{INF,15,INF,18,25,INF,0} //대칭임
		}
	};
	prim(&g, 0);
	return 0;
}