#include <stdio.h>
#pragma warning(disable:4996)

int dp[1001][10];
int main(){
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == 1) {
				dp[i][j]++;
				continue;
			}
			int total = 0;
			for (int k = 0; k <= j; k++) {
				total += dp[i - 1][k];
				total %= 10007;
			}
			dp[i][j] = total;
		}
	}
	int ans = 0;
	for (int i = 0; i < 10; i++)
		ans += dp[N][i];
	printf("%d", ans % 10007);
}