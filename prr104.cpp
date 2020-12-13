#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct GraphNode {
	int vertex;
	GraphNode* link;
}GraphNode;
typedef struct GraphType {
	int n; //vertex개수
	GraphNode* adj_list[MAX]; //포인터 배열
}GraphType;

void init(GraphType* g) {
	g->n = 0;
	for (int i = 0; i < MAX; i++)
		g->adj_list[i] = NULL;
}
void insert_vertex(GraphType* g, int v) {
	if (g->n + 1 > MAX) {
		fprintf(stderr, "정점의 개수 초과\n");
		return;
	}
	else g->n++; //vertex개수 증가
}
void insert_edge(GraphType* g, int u, int v) {
	if (u >= MAX || v >= MAX) {
		fprintf(stderr, "정점 번호 오류\n");
		return;
	}
	else {
		GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
		node->vertex = v;
		node->link = g->adj_list[u];
		g->adj_list[u] = node;
	}
}
void print_adj_list(GraphType* g) {
	for (int i = 0; i < g->n; i++) {
		GraphNode* p = g->adj_list[i];
		printf("vertex %d의 adj list:  ",i);
		for (; p->link != NULL; p = p->link)
			printf("%d -> ", p->vertex);
		printf("%d\n", p->vertex);
	}
}
int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);

	for (int i = 0; i < 4; i++)
		insert_vertex(g, i);
	insert_edge(g, 0, 1);
	insert_edge(g, 1, 0); //대칭아니어서, 직접 양방향으로 넣어줘야한다
	insert_edge(g, 0, 2);
	insert_edge(g, 2, 0);
	insert_edge(g, 0, 3);
	insert_edge(g, 3, 0);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 1);
	insert_edge(g, 2, 3);
	insert_edge(g, 3, 2);

	print_adj_list(g);

	free(g);
	return 0;
}
