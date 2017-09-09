#include<stdio.h>
#define INF 999999999
#pragma warning(disable:4996)

int graph[1000][1000];

//Floyd
int main() {
	int V, E;
	int K;
	int u, v, w;
	scanf("%d %d ", &V, &E);
	scanf("%d ", &K);
	for (int i = 1; i <= V; i++)
		for (int j = 1; j <= V; j++) {
			if (i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = INF;
		}
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		if(graph[u][v] > w)
			graph[u][v] = w;
	}
	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				if (graph[i][j] > graph[i][k] + graph[k][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}
	for (int i = 1; i <= V; i++) {
			if (graph[K][i] == INF)
				printf("INF\n");
			else
				printf("%d\n", graph[K][i]);
	}
}