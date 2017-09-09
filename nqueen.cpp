#include<stdio.h>
#pragma warning(disable:4996)

int visit[16][16] = { 0 };
int left[32] = { 0 };
int right[32] = { 0 };
int vert[16] = { 0 };
int N = 0;

void nQueen(int x, int y, int * count){
	if (x > N){
		*count = *count + 1;
		return;
	}
	if (y > N)
		return;
	if (left[x + y] == 1 || right[x - y + N] == 1 || vert[y] == 1){
		nQueen(x, y + 1, count);
		return;
	}
	visit[x][y] = 1;
	left[x + y] = 1;
	right[x - y + N] = 1;
	vert[y] = 1;
	nQueen(x + 1, 1, count);
	visit[x][y] = 0;
	left[x + y] = 0;
	right[x - y + N] = 0;
	vert[y] = 0;
	nQueen(x, y + 1, count);
}

/*void nQueen(int x, int y, int N, int* count){
	if (visit[x][y] == 1)
		return;
	if (x == N){
		(*count) = (*count)+1;
		return;
	}//base case
	int prev[16][16] = { 0 };
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			prev[i][j] = visit[i][j];
		}
	}
	visit[x][y] = 1;
	for (int i = 1; i <= N; i++){
		visit[x][i] = 1; // 가로 전부 1
		visit[i][y] = 1; // 세로 전부 1
		if (x + i <= N&& y + i <= N)
			visit[x + i][y + i] = 1;
		if (x + i <= N&& y - i >= 1)
			visit[x + i][y - i] = 1;
		if (x - i >= 1 && y + i <= N)
			visit[x - i][y + i] = 1;
		if (x - i >= 1 && y - i >= 1)
			visit[x - i][y - i] = 1; //대각선
	}
	for (int i = 1; i <= N; i++)
		nQueen(x + 1, i, N, count);
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			visit[i][j] = prev[i][j];
		}
	}
}
*/

int main(){
	int count = 0;
	scanf("%d", &N);
	nQueen(1, 1, &count);
	printf("%d", count);
}