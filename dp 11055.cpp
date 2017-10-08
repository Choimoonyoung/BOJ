#include <algorithm>
#pragma warning (disable:4996)
using namespace std;
int dp[1000];
int arr[1000];
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < N; i++) {
		if (i == 0) { dp[i] = arr[i]; continue; }
		dp[i] = arr[i];
		for (int j = 0; j < i; j++)
			if (arr[j] < arr[i])
				dp[i] = max(dp[i],dp[j] + arr[i]);
	}
	int ans = 0;
	for (int i = 0; i < N; i++)
		ans = max(ans, dp[i]);
	printf("%d", ans);
}