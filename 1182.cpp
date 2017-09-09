#include<stdio.h>
#pragma warning (disable:4996)

int N, S;
int count = 0;
int arr[21];
int num[21];



void sum(int len) {
	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum += num[i];
	}
	if (S == sum)
		count++;
}


void sub(int begin, int end, int length, int idx) {
	if (length == 0) {
		sum(idx);
		return;
	}
	if (begin > end || end - begin + 1 < length || idx > 20)
		return;
	for (int i = begin; i <= end; i++) {
		num[idx] = arr[i];
		sub(i + 1, end, length - 1, idx + 1);
	}
}

int main() {
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= N; i++) {
		sub(0, N - 1, i, 0);
	}
	printf("%d", count);
}