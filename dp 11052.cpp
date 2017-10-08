#include <algorithm>
#pragma warning (disable:4996)
#define MAX 9999999

using namespace std;
int dp[1001];
int arr[1001];

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	for (int i = 1; i <= N; i++) {
		int total = 0;
		for (int j = 1; j <=i; j++) {
			total = max(total, dp[i - j] + arr[j-1]);
		}
		dp[i] = total;
	}
	printf("%d", dp[N]);
}