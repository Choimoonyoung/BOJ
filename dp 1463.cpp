#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int dp[1000001];
int dfs(int n) {
	if (n == 1)
		return 0;
	if (dp[n] != 0)
		return dp[n];
	if (n % 3 == 0 && n % 2 == 0)
		dp[n] = min(dfs(n / 3), dfs(n / 2));
	else if (n % 3 == 0)
		dp[n] = min(dfs(n / 3), dfs(n - 1));
	else if (n % 2 == 0)
		dp[n] = min(dfs(n - 1), dfs(n / 2));
	else
		dp[n] = dfs(n - 1);
	return ++dp[n];

}
int main() {
	int N;
	scanf("%d", &N);
	printf("%d",dfs(N));
}