#include <stdio.h>
#pragma warning(disable:4996)


int main() {
	int N, A[10000], X;
	scanf("%d %d ", &N, &X);
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		A[i] = tmp;
	}
	for (int i = 0; i < N; i++) {
		if (A[i] < X)
			printf("%d ", A[i]);
	}
}