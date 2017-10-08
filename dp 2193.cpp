#include <algorithm>
#pragma warning (disable:4996)
using namespace std;

long long dp[91] = { 0 };
int main() {
	int N;
	scanf("%d", &N);
	dp[2] = 1;
	for (int i = 3; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	if (N == 1) printf("%d", 1);
	else printf("%lld", dp[N] + dp[N - 1]);
}