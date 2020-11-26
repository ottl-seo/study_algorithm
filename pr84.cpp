/* day 67 - 다익스트라 오류 해결 및 복습 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L //무한대(연결이 없는 경우)

typedef struct GraphType {
	int n; //정점 개수
	int weight[MAX_VERTICES][MAX_VERTICES]; // 각 정점 사이 거리 표현
}GraphType;

int distance[MAX_VERTICES]; // start vertex로부터 각 정점까지의 최단 거리
int found[MAX_VERTICES]; //방문한 정점 표시

int choose(int distance[], int n, int found[]) { /* distance 중에서 가장 짧은 vertex번호를 리턴 */
	int i, min, min_vertex;
	min = INT_MAX;
	min_vertex = -1; // 최소거리 갖는 vertex: 없는 vertex로 일단 초기화
	for (i = 0; i < n; i++) {
		if (distance[i] < min && !found[i]){
			min = distance[i]; // min값 갱신
			min_vertex = i; //최소거리 갖는 vertex
		}
	}
	return min_vertex; //vertex 번호 반환
}
void print_status(GraphType* g) {
	static int step = 1;
	printf("STEP %d:\n", step++); //step 1, 2, ...
	printf(" distance: ");
	for (int i = 0; i < g->n; i++)
		if (distance[i] == INF) { printf(" * "); }
		else { printf("%2d ", distance[i]); }
	printf("\n found: ");
	for (int i = 0; i < g->n; i++)
		printf("%2d ", found[i]);
	printf("\n\n");
}
void shortest_path(GraphType* g, int start) { // start_vertex 번호 받기
	int i, u, w;

	/* 1.초기화 */
	for (int i = 0; i < g->n; i++){
		found[i] = FALSE;
		distance[i] = g->weight[start][i]; //start vertex로부터의 정점까지의 거리 (1,INF,3 등등...)
	}
	/* 2.start vertex 설정 */
	found[start] = TRUE;
	distance[start] = 0;

	/* 3.최단 vertex를 찾아서 found에 추가 */
	for (int i = 0; i < g->n - 1; i++) {
		print_status(g); //step 출력
		u = choose(distance, g->n, found); // 제일 작은 distance 갖는 vertex 반환 == u
		found[u] = TRUE;

		/* 4.u를 거쳐가는 게 더 짧을 경우, 갱신 */
		for (w = 0; w < g->n; w++) {
			if (!found[w]) { // !found 주의...
				if (distance[u] + g->weight[u][w] < distance[w]) //더 짧을 경우
					distance[w] = distance[u] + g->weight[u][w]; // distance[w]값 갱신
			}
		}
	}
}
int main() {
	GraphType g = {
		7,
		{
		{0,7,INF,INF,3,10,INF},
		{7,0,4,10,2,6,INF},
		{INF,4,0,2,INF,INF,INF},
		{INF,10,2,0,11,9,4},
		{3,2,INF,11,0,INF,5},
		{10,6,INF,9,INF,0,INF},
		{INF,INF,INF,4,5,INF,0}
		}
	};
	shortest_path(&g, 0); //0번 vertex에서 모든 vertex까지의 shortest path

	return 0;
}
