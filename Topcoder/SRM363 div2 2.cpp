#include <algorithm>

using namespace std;

long long dp[51] = { 0 };

long long dfs(int n) {
	if ( n<= 2)
		return dp[2] = 1;
	if (dp[n] != 0)
		return dp[n];
	long long total = 0;
	for (int i = n - 2; i >= n - 2 - i; i -= 2) {
		if (i == n - 2 - i)
			total += (dfs(i)*dfs(i));
		else
			total += (2 * dfs(i)* dfs(n-2-i));
	}
	return dp[n] = total;
}
long long countPerfect(int n) {
	return dfs(n);
}

/*
long long countPerfect(int n) {
	dp[0] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = i - 2; j >= 0; j -= 2) {
			dp[i] += (dp[j]* dp[i - 2 - j]);
		}
	}
	return dp[n];
}*/

int main() {
	printf("%ld", countPerfect(8));
}