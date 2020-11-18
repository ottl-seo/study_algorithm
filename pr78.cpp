/**/
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

/* ==================== Quick Sort ======================= */
