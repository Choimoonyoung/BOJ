#include <algorithm>
#define MAX 100001
#pragma warning(disable:4996)
using namespace std;
int dp[100001];
int main() {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		int total = MAX;
		for (int j = 1; j*j <= i; j++) {
			total = min(total, dp[i - j*j]);
		}
		dp[i] = ++total;
	}
	printf("%d", dp[N]);
}
