#include<stdio.h>
#include<algorithm>

using namespace std;

int N;
int A[51], B[51];

int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < N; i++){
		scanf("%d", &B[i]);
	}
	sort(A, A + N);
	sort(B, B + N);
	int sum = 0;
	for (int i = 0; i < N; i++){
		sum += A[i] * B[N - i - 1];
	}
	printf("%d", sum);
}
