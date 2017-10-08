#include <algorithm>
#pragma warning (disable:4996)
using namespace std;
int arr[2][100001];
int dp[2][100001];

int main() {
	int T, n;
	scanf("%d", &T);
	for (int kk = 0; kk < T; kk++) {
		scanf("%d", &n);
		for (int i = 0; i < 2; i++) 
			for (int j = 0; j < n; j++) 
				scanf("%d", &arr[i][j]);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2; j++) {
				if (i == 0) {
					dp[j][i] = arr[j][i]; continue;
				}
				if (i == 1) {
					dp[j][i] = dp[1 - j][i - 1] + arr[j][i];
					continue;
				}
				dp[j][i] = max(dp[1 - j][i - 1], dp[1 - j][i - 2]) + arr[j][i];
			}
		}

		printf("%d\n", max(dp[0][n - 1], dp[1][n - 1]));

		for (int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++)
				dp[i][j] = 0;

	}
}