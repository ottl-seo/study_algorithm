/* day 67 - ���ͽ�Ʈ�� ���� �ذ� �� ���� */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L //���Ѵ�(������ ���� ���)

typedef struct GraphType {
	int n; //���� ����
	int weight[MAX_VERTICES][MAX_VERTICES]; // �� ���� ���� �Ÿ� ǥ��
}GraphType;

int distance[MAX_VERTICES]; // start vertex�κ��� �� ���������� �ִ� �Ÿ�
int found[MAX_VERTICES]; //�湮�� ���� ǥ��

int choose(int distance[], int n, int found[]) { /* distance �߿��� ���� ª�� vertex��ȣ�� ���� */
	int i, min, min_vertex;
	min = INT_MAX;
	min_vertex = -1; // �ּҰŸ� ���� vertex: ���� vertex�� �ϴ� �ʱ�ȭ
	for (i = 0; i < n; i++) {
		if (distance[i] < min && !found[i]){
			min = distance[i]; // min�� ����
			min_vertex = i; //�ּҰŸ� ���� vertex
		}
	}
	return min_vertex; //vertex ��ȣ ��ȯ
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
//
void shortest_path(GraphType* g, int start) { // start_vertex ��ȣ �ޱ�
	int i, u, w;

	/* 1.�ʱ�ȭ */
	for (int i = 0; i < g->n; i++){
		found[i] = FALSE;
		distance[i] = g->weight[start][i]; //start vertex�κ����� ���������� �Ÿ� (1,INF,3 ���...)
	}
	/* 2.start vertex ���� */
	found[start] = TRUE;
	distance[start] = 0;

	/* 3.�ִ� vertex�� ã�Ƽ� found�� �߰� */
	for (int i = 0; i < g->n - 1; i++) {
		print_status(g); //step ���
		u = choose(distance, g->n, found); // ���� ���� distance ���� vertex ��ȯ == u
		found[u] = TRUE;

		/* 4.u�� ���İ��� �� �� ª�� ���, ���� */
		for (w = 0; w < g->n; w++) {
			if (!found[w]) { // !found ����...
				if (distance[u] + g->weight[u][w] < distance[w]) //�� ª�� ���
					distance[w] = distance[u] + g->weight[u][w]; // distance[w]�� ����
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
	shortest_path(&g, 0); //0�� vertex���� ��� vertex������ shortest path

	return 0;
}