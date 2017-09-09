#pragma warning(disable:4996)
#include <stdio.h>

int visit[11][11];
int right[30] = { 0 };
int N;
/*
void bishop(int x, int y, int actual, int * count){
	if (x + y > 2 * N){
		if (*count < actual)
			*count = actual;
		return;
	}
	if (x + y <= N + 1){
		for (int i = 1; i <= x + y - 1; i++){
			if (visit[x][y] == 1 && right[x - y + N] == 0){
				right[x - y + N] = 1;
				if (x + y > N)
					bishop(N, x + y - N + 1, actual + 1, count);
				else
					bishop(x + y, 1, actual + 1, count);
				right[x - y + N] = 0;
			}
			bishop(x - 1, y + 1, actual, count);
		}
	}
	else{
		for (int i = 1; i <= 2*N-x-y+1; i++){
			if (visit[x][y] == 1 && right[x - y + N] == 0){
				right[x - y + N] = 1;
				if (x + y > N)
					bishop(N, x + y - N + 1, actual + 1, count);
				else
					bishop(x + y, 1, actual + 1, count);
				right[x - y + N] = 0;
			}
			bishop(x - 1, y + 1, actual, count);
		}
	}
}*/

/*void bishop(int k, int actual, int* count){//k = x+y
	int tmp = 0;
	if (k > 2 * N){
		if (*count < actual)
			*count = actual;
		return;
	}
	if (k <= N){
		for (int i = 1; i <= k- 1; i++){
			if (visit[k - i][i] == 1)
				tmp = 1;
			if (visit[k - i][i] == 1 && right[k - 2 * i + N] == 0){
				right[k - 2 * i + N] = 1;
				bishop(k + 1, actual + 1, count);
				right[k - 2 * i + N] = 0;
			}
		}
	}
	else{
		for (int i = 0; i <= 2*N-k; i++){
			if (visit[N - i][k - N + i] == 1)
				tmp = 1;
			if (visit[N-i][k-N+i] == 1 && right[3*N -k-2*i] == 0){
				right[3 * N - k - 2 * i] = 1;
				bishop(k + 1, actual + 1, count);
				right[3 * N - k - 2 * i] = 0;
			}
		}
	}
	if (tmp == 0 || k == 2 * N)
		bishop(k + 1, actual, count);
}*/
/*void bishop(int x, int y, int actual, int * count){
	if (x + y > 2 * N){
		if (*count < actual)
			*count = actual;
		return;
	}
	if (visit[x][y] == 0)
	if (visit[x][y] == 1 && right[x-y+N] == 0){
		right[x - y + N] = 1;
		if (x + y > N)
			bishop(N, x + y - N + 1, actual + 1, count);
		else
			bishop(x + y, 1, actual + 1, count);
		right[x - y + N] = 0;
	}
	if (x>1 && y<N)
		bishop(x - 1, y + 1, actual, count);
	else{
		if (x + y > N)
			bishop(N, x + y - N + 1, actual, count);
		else
			bishop(x + y, 1, actual, count);
	}
}*/
/*void bishop(int x, int y, int actual, int* count){
	if (x > N){
		if (*count<actual)
			*count = actual;
		return;
	}
	if (y > N){
		bishop(x + 1, 1, actual, count);
		return;
	}
	if (visit[x][y] == 0){
		bishop(x, y + 1, actual, count);
		return;
	}
	if (left[x + y] == 1 || right[x - y + N] == 1){
		bishop(x, y + 1, actual, count);
		return;
	}
	left[x + y] = right[x - y + N] = 1;
	bishop(x, y + 1, actual + 1, count);
	left[x + y] = right[x - y + N] = 0;
	bishop(x, y + 1, actual, count);
}*/
/*void bishop(int x, int y, int N, int actual, int *count){
	if (x > N)
		return;
	if (visit[x][y] == 0){
		bishop(x, y + 1, N, actual, count);
		return;
	}
	//base case
	int temp = 0;
	for (int i = 1; i < x; i++){
		if (x - i >= 1 && y - i >= 1){
			if (visit[x - i][y - i] == 2){
				temp = 1;
				break;
			}
		}
		if (x - i >= 1 && y + i <= N){
			if (visit[x - i][y + i] == 2){
				temp = 1;
				break;
			}
		}
	}
	//대각선 방향에 2가 있는지 없는지 보고 있으면 temp = 1 없으면 0
	if (temp == 0){
		visit[x][y] = 2;
		if (actual >= *count)
			*count = actual;
		if (y + 1 <= N)
			bishop(x, y + 1, N, actual+1, count);
		else
			bishop(x + 1, 1, N, actual+1,count);
	}
	visit[x][y] = 1;
	if (y + 1 <= N)
		bishop(x, y + 1, N, actual, count);
	else
		bishop(x + 1, 1, N, actual, count);

}*/


void bishop(int k, int actual, int* count){//k = x+y
	int tmp = 0;
	if (k > 2 * N){
		if (*count < actual)
			*count = actual;
		return;
	}
	if (k <= N){
		for (int i = 1; i <= k - 1; i++){
			if (visit[k - i][i] == 1)
				tmp = 1;
			if (visit[k - i][i] == 1 && right[k - 2 * i + N] == 0){
				right[k - 2 * i + N] = 1;
				bishop(k + 2, actual + 1, count);
				right[k - 2 * i + N] = 0;
			}
		}
	}
	else{
		for (int i = 0; i <= 2 * N - k; i++){
			if (visit[N - i][k - N + i] == 1)
				tmp = 1;
			if (visit[N - i][k - N + i] == 1 && right[3 * N - k - 2 * i] == 0){
				right[3 * N - k - 2 * i] = 1;
				bishop(k + 2, actual + 1, count);
				right[3 * N - k - 2 * i] = 0;
			}
		}
	}
	bishop(k + 2, actual, count);
}

int bishopa(int* count){
	bishop(2, 0, count);
	int max = *count;
	*count = 0;
	bishop(3, 0, count);
	return (max + *count);
}

int main(){
	int count = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			scanf("%d", &visit[i][j]);
		}
	}
	count = bishopa(&count);
	printf("%d", count);
}
