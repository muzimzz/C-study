#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100	
#define INF	1000000

typedef struct GraphType {
	int n;	// 정점의 개수
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int A[MAX_VERTICES][MAX_VERTICES];

void printA(GraphType* g)
{
	int i = 0, j = 0;
	
	for (i = 0; i < g->n; i++)
	{
		for (j = 0; j < g->n; j++)
		{
			if (A[i][j] == INF)
				printf("  * ");
			else
				printf("%3d ", A[i][j]);
		}

		printf("\n");
	}

	printf("\n\n");
}

void floyd(GraphType* g)
{
	int i = 0, j = 0, k = 0;

	for (i = 0; i < g->n; i++)	// g->weight로 결과 그래프 초기화
		for (j = 0; j < g->n; j++)
			A[i][j] = g->weight[i][j]; 

	printf("초기상태: \n");
	printA(g);

	for (k = 0; k < g->n; k++) {		// 거쳐가는 정점
		for (i = 0; i < g->n; i++)		// 시작 정점
			for (j = 0; j < g->n; j++)	// 끝 정점
				if (A[i][k] + A[k][j] < A[i][j]) 
					A[i][j] = A[i][k] + A[k][j];

		printf("%d 정점을 거친 경로 갱신 결과: \n", k);
		printA(g);
	}
}

int main(void)
{
	GraphType g = { 7,
	{{ 0,  7,  INF, INF,   3,  10, INF },
	{ 7,  0,    4,  10,   2,   6, INF },
	{ INF,  4,    0,   2, INF, INF, INF },
	{ INF, 10,    2,   0,  11,   9,   4 },
	{ 3,  2,  INF,  11,   0, INF,   5 },
	{ 10,  6,  INF,   9, INF,   0, INF },
	{ INF, INF, INF,   4,   5, INF,   0 } }
	};

	floyd(&g);

	return 0;
}
