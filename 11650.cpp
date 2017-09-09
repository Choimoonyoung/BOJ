#include<stdio.h>
#include<algorithm>

struct point{
	int x, y;
	bool operator()(point p, point q){
		if (p.x != q.x)return p.x < q.x;
		return p.y < q.y;
	}
}A[100005];

int main(){
	freopen("input.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)scanf("%d %d", &A[i].x, &A[i].y);
	std::stable_sort(A, A + N, point());
	for (int i = 0; i < N; i++){
		printf("%d %d\n", A[i].x, A[i].y);
	}
	return 0;
}