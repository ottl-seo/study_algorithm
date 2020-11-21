/* Prim�� MST �ڵ� */
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

typedef struct GraphType {
	int n; //������ ����
	int weight[MAX_VERTICES][MAX_VERTICES]; //vertex ������ ��ķ� ǥ��
}GraphType;

int selected[MAX_VERTICES]; //MST�� ���õ� vertex�� ����
int dist[MAX_VERTICES]; //MST ���� vertex���� �� vertex������ �Ÿ�...

int get_min_vertex(int n) { /* MST�� vertex�κ��� ���� ª�� distance�� ���� vertex ��ȯ�ϴ� �Լ� */
	int v, i;
	for (i = 0; i < n; i++) {
		if (!selected[i]) {
			v = i; //���� ���� �� �� ù��° vertex v ã��
			break;
		}
	}
	for (i = 0; i < n; i++)
		if (!selected[i] && (dist[i] < dist[v]))v = i; //�ּڰ� ã��
	return v;
}
void prim(GraphType* g, int s) {
	int i, u, v;
	for (u = 0; u < g->n; u++)
		dist[u] = INF; //��� distance�� ���Ѵ� --�ʱ�ȭ
	dist[s] = 0; //0�� ������ ����

	printf("<Prim MST ���>\n");
	for (i = 0; i < g->n; i++) {
		u = get_min_vertex(g->n);
		selected[u] = TRUE; // MST�κ��� distance ���� ª�� vertex u�� MST�� �߰�
		
		if (dist[u] == INF)return; //���� ª�� �Ÿ��� ���Ѵ�� ����!
		printf("vertex %d\n", u);
		for (v = 0; v < g->n; v++) {
			if (!selected[v] && g->weight[u][v] < dist[v])
				dist[v] = g->weight[u][v];
		}
	}
}
int main() {
	GraphType g = { 7, //vertex�� = 7
		{
		{0,29,INF,INF,INF,10,INF}, //���� ����� edge ���� ��
		{29,0,16,INF,INF,INF,15},
		{INF,16,0,12,INF,INF,INF},
		{INF,INF,12,0,22,INF,18},
		{INF,INF,INF,22,0,27,25},
		{10,INF,INF,INF,27,0,INF},
		{INF,15,INF,18,25,INF,0} //��Ī��
		}
	};
	prim(&g, 0);
	return 0;
}