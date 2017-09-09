#include<stdio.h>
#pragma warning(disable:4996)

int visit[26] = { 0 };
int arr[21][21];
int R, C; //R 가로 C세로
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
/*
ABCD
EFAD
ASDA
NGHZ
*/
void one(int x, int y, int count,int* max){
	if (R == 1 && C == 1){
		*max = 1;
		return;
	}
	if (visit[arr[x][y] - 'A'] == 1){
		if (count > *max)
			*max = count;
		return;
	}
	visit[arr[x][y] - 'A'] = 1;
	for (int i = 0; i < 4; i++){
		if (x + dx[i] >= 0 && x + dx[i]<R && y+ dy[i] >= 0 && y + dy[i]<C){
			one(x + dx[i], y + dy[i], count+1 ,max);
		}
	}
	visit[arr[x][y] - 'A'] = 0;
}

int main(){
	scanf("%d %d", &R, &C);
	getchar();
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			scanf("%c", &arr[i][j]);
		}
		getchar();
	}
	int max = 0;
	one(0, 0, 0, &max);
	printf("%d", max);
}