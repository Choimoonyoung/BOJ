#include<stdio.h>
#define INF 999999999
#pragma warning(disable:4996)

int g[20001][20001];
int d[20001], c[20001];
int main() {
	int V, E;
	int K;
	int u, v, w;
	scanf("%d %d", &V, &E);
	scanf("%d", &K);
	for (int i = 0; i <= V; i++) {
		d[i] = INF;
	}
	for (int i = 1; i <= E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		if (g[u][v] == 0)
			g[u][v] = w;
		else if (g[u][v] > w)
			g[u][v] = w;
	}
	d[K] = 0;
	int min;
	for (int k = 1;k<=V;k++) {
		min = 0;
		for (int i = 0; i <= V; i++) {
			if (c[i] == 0 && d[i] < d[min])
				min = i;
		}
		c[min] = 1;
		for (int i = 1; i <= V; i++) {
		
			if (d[i] > d[min] + g[min][i] && g[min][i] !=0) {
				d[i] = d[min] + g[min][i];
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (d[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", d[i]);
	}
}