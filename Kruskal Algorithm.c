#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define INF 1000

int parent[MAX_VERTICES];	// 부모 노드

// 초기화
void set_init(int n)
{
	for (int i = 0; i < n; i++)
		parent[i] = -1;
}

// 루트노드의 인덱스 반환.
int set_find(int curr)
{
	if (parent[curr] == -1)
		return curr; 			// 루트 
	while (parent[curr] != -1) curr = parent[curr];
	return curr;
}

void set_union(int a, int b)
{
	int root1 = set_find(a);
	int root2 = set_find(b);
	if (root1 != root2) {	// 두 루트 중 인덱스가 큰 루트의 값을  
		if (root1 < root2)	// 다른 루트의 인덱스번호로 바꾼다
			parent[root2] = root1;
		else
			parent[root1] = root2;
	}
}

struct Edge {		// 간선 구조체 (시작정점, 도착정점, 가중치)
	int start, end, weight;
};

typedef struct GraphType {
	int n;	// 간선의 개수
	struct Edge edges[MAX_VERTICES * MAX_VERTICES];	// 간선들의 집합
} GraphType;

// 그래프 초기화 
void graph_init(GraphType* g)
{
	g->n = 0;
	for (int i = 0; i < MAX_VERTICES * MAX_VERTICES; i++) {
		g->edges[i].start = 0;
		g->edges[i].end = 0;
		g->edges[i].weight = INF; // infinite
	}
}

// 간선 삽입 
void insert_edge(GraphType* g, int start, int end, int w)
{	// 간선 집합[n]에 시작정점, 끝정점, 가중치 정보 추가
	g->edges[g->n].start = start;
	g->edges[g->n].end = end;
	g->edges[g->n].weight = w;
	g->n++;
}
// qsort()에 사용되는 함수
int compare(const void* a, const void* b)
{
	struct Edge* x = (struct Edge*)a;
	struct Edge* y = (struct Edge*)b;
	return (x->weight - y->weight);
}

// kruskal 최소 비용 신장 트리 프로그램
void kruskal(GraphType* g)
{
	int edge_accepted = 0;	// 선택된 간선의 수	
	int edge_accepted_weight = 0; // 선택된 간선들의 가중치 합
	int uset, vset;			// 정점 u와 정점 v의 집합 번호
	struct Edge e;

	set_init(g->n);				// 집합 초기화
	qsort(g->edges, g->n, sizeof(struct Edge), compare);

	printf("크루스칼 최소 신장 트리 알고리즘 \n");

	int i = 0;
	while (edge_accepted < (g->n - 1))	// 간선의 수 < (n-1)
	{									// 트리의 조건: 
		e = g->edges[i];
		uset = set_find(e.start);		// 정점 u의 집합 번호 
		vset = set_find(e.end);		// 정점 v의 집합 번호
		if (uset != vset) {			// 서로 속한 집합이 다르면
			printf("간선 (%d,%d) %d 선택\n", e.start, e.end, e.weight);
			edge_accepted++;
			edge_accepted_weight += e.weight;
			set_union(uset, vset);	// 두개의 집합을 합친다.
		}
		i++;
	}

	printf("\n간택된 간선의 수:%d", edge_accepted);
	printf("\n간택된 간선의 가중치 합: %d", edge_accepted_weight);

	return;
}

int main_kruskal(void)
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	graph_init(g);

	insert_edge(g, 0, 1, 29);
	insert_edge(g, 1, 2, 16);
	insert_edge(g, 2, 3, 12);
	insert_edge(g, 3, 4, 22);
	insert_edge(g, 4, 5, 27);
	insert_edge(g, 5, 0, 10);
	insert_edge(g, 6, 1, 15);
	insert_edge(g, 6, 3, 18);
	insert_edge(g, 6, 4, 25);

	kruskal(g);

	free(g);
	return 0;
}
