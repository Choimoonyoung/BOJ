#include <stdio.h>
#pragma warning(disable:4996)
int dp[1000000];
int main() {
	int N;
	scanf("%d", &N);
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= 15746;
	}
	printf("%d", dp[N]);
}