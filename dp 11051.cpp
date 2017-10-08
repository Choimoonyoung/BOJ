#include <stdio.h>
#pragma warning(disable:4996)
int dp[1001][1001];

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		for (int k = 0; k <= i; k++) {
			if (k == 0 || i == 1) { dp[i][k] = 1; continue; }
			dp[i][k] = (dp[i - 1][k] + dp[i - 1][k - 1])%10007;
		}
	}
	printf("%d", dp[N][K]);
}