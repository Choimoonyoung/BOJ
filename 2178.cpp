/*#include<stdio.h>
#include<queue>
using namespace std;
#define inf 2100000000
// #pragma warning(disable:4996)

struct point{
	int x, y;
};
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
int N, M, D[105][105];
char A[105][105];

queue<point> Q;

void bfs(int sx, int sy){
	point start = { sx, sy };
	Q.push(start);
	while (!Q.empty()){
		point pos = Q.front(); Q.pop();
		if (pos.x == N - 1 && pos.y == M - 1)break;
		for (int i = 0; i < 4; i++){
			int nx = pos.x + dx[i];
			int ny = pos.y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)continue;
			if (D[pos.x][pos.y] + 1 < D[nx][ny] && (A[nx][ny]=='1')){
				D[nx][ny] = D[pos.x][pos.y] + 1;
				point tmp = { nx, ny };
				Q.push(tmp);
			}
		}
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	scanf("%d %d ", &N, &M);
	for (int i = 0; i < N; i++)scanf("%s ", A[i]);
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)D[i][j] = inf;
	D[0][0] = 1;
	bfs(0,0);
	printf("%d\n", D[N - 1][M - 1]);
}
*/
#include<stdio.h>
#include<queue>
#include<stdlib.h>

using namespace std;
int N, M;
char maze[101][101];
int D[101][101];

typedef struct point{
	int x;
	int y;
}Point;

queue<Point> Q;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(){
	scanf("%d %d", &N, &M);
	char* a = (char*)malloc(sizeof(char)*(M+1));
	for (int i = 1; i <= N; i++){
		scanf("%s", a);
		for (int j = 1; j <= M; j++){
			maze[i][j] = a[j - 1]-'0';
			D[i][j] = 2100000000;
		}
	}
	free(a);
	Point p;
	p.x = 1;
	p.y = 1;
	D[1][1] = 1;
	Q.push(p);
	while (Q.empty() != 1){
		Point tmp = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++){
			int nx = tmp.x + dx[i];
			int ny = tmp.y + dy[i];
			if (maze[nx][ny] == 0)
				continue;
			if (tmp.x == N&&tmp.y == M)
				break;
			if (nx>N || nx<1 || ny>M || ny < 1)
				continue;
			if (D[nx][ny] > D[tmp.x][tmp.y]+1){
				D[nx][ny] = D[tmp.x][tmp.y] + 1;
				Q.push({ nx, ny });
			}
		}
	}
	printf("%d", D[N][M]);
	
	return 0;
}