#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

typedef struct GraphType {
	int n; //���õ� vertex�� ����
	int weight[MAX_VERTICES][MAX_VERTICES]; 
}GraphType;

int found[MAX_VERTICES]; //���õ� vertex�� ����
int distance[MAX_VERTICES]; //spanning tree���� vertex���� �� vertex������ distance

int choose(int distance[], int n, int found[]) { //sp �������κ��� ���� ª�� dist�� ���� vertex ��ȯ
	int i, min, min_vertex;
	min = INT_MAX;
	min_vertex = -1;
	for (i = 0; i < n; i++) {
		if (distance[i] < min && !found[i]) {
			min = distance[i]; //���� ���� �� �� �ּҰŸ� vertex ã��
			min_vertex = i;
		}
		return min_vertex;
	}
}
void print_status(GraphType* g) {
	static int step = 1;
	printf("STEP %d: \n", step++);
	printf("distance: ");
	for (int i = 0; i < g->n; i++) {
		if (distance[i] == INF)
			printf(" * "); //���Ѵ�� '*'�� ǥ��
		else
			printf("%2d ", distance[i]);
	}
	printf("\n");
	printf("found: ");
	for (int i = 0; i < g->n; i++)
		printf("%2d ", found[i]);
	printf("\n\n");
}
/* void shortest_path(GraphType* g, int start) */

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
	
}