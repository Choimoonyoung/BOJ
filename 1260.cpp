#include<stdio.h>
#include<queue>

using namespace std;

int N, M, V;
int graph[1001][1001];

int main(){
	scanf("%d %d %d", &N, &M, &V);
	for (int i = 0; i < M; i++){
		int x, y;
		scanf("%d", &x);
		scanf("%d", &y);
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
}