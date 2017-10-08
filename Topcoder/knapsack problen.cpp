#include <stdio.h>
#include <algorithm>

using namespace std;
int main() {
	int ws[6] = { 0,3,4,1,2,3 };
	int ps[6] = { 0,2,3,2,3,6 };
	int maxw = 10;
	int dp[6][11] = { 0 };
	int ret = 0;

	for (int i = 1; i <= 5; i++) {
		for (int j = 0; j <= maxw; j++) {
			if (j < ws[i]) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i-1][j - ws[i]] + ps[i], dp[i-1][j] );
				ret = max(dp[i][j], ret);
			}
		}
	}
	printf("%d", ret);
}