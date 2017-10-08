#include <algorithm>
#pragma warning (disable:4996)
#define MAX 99999999

using namespace std;
int arr[100];
int dp[10000];
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (int i = 1; i <= k; i++) {
		int total = MAX;
		for (int idx = 0; idx < n; idx++) {
			if (i >= arr[idx])
				total = min(total, dp[i - arr[idx]]);
		}
		if (total == MAX || total == -1) dp[i] = MAX;
		else dp[i] = ++total;
	}
	if(dp[k] == MAX) printf("-1");
	else printf("%d", dp[k]);

}