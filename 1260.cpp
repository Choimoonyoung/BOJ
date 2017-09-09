#include<stdio.h>
#include<queue>
#pragma warning(disable: 4996)

using namespace std;
queue<int> Q;

int graph[1001][1001];
int visit[1001];
int N, M, V;

void dfs(int now) {
	if (visit[now] ==1)
		return;
	printf("%d ", now);
	visit[now] = 1;
	for (int i = 1; i <= N; i++) {
		if (graph[now][i] == 1) {
			dfs(i);
		}
	}
}

void bfs(int V) {
	Q.push(V);
	while (!Q.empty()) {
		int now =Q.front();
		printf("%d ", now);
		Q.pop();
		visit[now] = 1;
		for (int i = 1; i <= N; i++) {
			if (visit[i] == 0 && graph[now][i] ==1) {
				visit[i] = 1;
				Q.push(i);
			}
		}
	}
}
int main() {
	scanf("%d %d %d", &N, &M, &V);
	for (int i = 0; i < M; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	//graph ¿Ï¼º
	dfs(V);
	for (int i = 1; i <= N; i++)
		visit[i] = 0;
	printf("\n");
	bfs(V);
}