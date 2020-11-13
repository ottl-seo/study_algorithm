/* 인접리스트 복습 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct GraphNode {
	int vertex;
	GraphNode* link;
}GraphNode;

typedef struct GraphType {
	int n; //vertex의 개수
	GraphNode* adj_list[MAX]; //vertex 개수 크기의 포인터 배열
}GraphType;

void init(GraphType* g) {
	g->n = 0;
	for (int i = 0; i < MAX; i++)
		g->adj_list[i] = NULL; //포인터배열을 모두 NULL로 초기화
}
void insert_vertex(GraphType* g, int value); //생략

void insert_edge(GraphType* g, int head, int value) {
	if (head >= g->n || value >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류\n");
		return;
	}
	GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = value;
	node->link = g->adj_list[head]; //
	g->adj_list[head] = node;
}
