#include <algorithm>
#include <vector>

using namespace std;

int maxDonations(vector<int> donations) {
	int ans = 0;
	int dp[41] = { 0 };
	for (int j = 0; j <= 1; j++) {
		for (int i = j; i < donations.size() - 1+j; i++) {
			if (i < 2+j) 
				dp[i] = donations[i];
			else if (i == 2+j)
				dp[i] = donations[i] + dp[i - 2];
			else 
				dp[i] = max(dp[i - 2] + donations[i], dp[i - 3] + donations[i]);
			ans = max(dp[i], ans);
		}
	}
	return ans;
}

int main() {
	vector<int> donations = { 11, 15 };
	printf("%d", maxDonations(donations));
}