#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int dp[51] = { 0 };

int dfs(int n, vector<string> relations) {
	if (dp[n] != 0)
		return dp[n];
	int count = 0;
	for (int i = 0; i < relations.size(); i++) {
		if (relations[n][i] == 'Y')
			count += dfs(i,relations);
	}
	if (count == 0) return dp[n] = 1;
	return dp[n] = count;
}

long long totalSalary(vector<string> relations) {
	long long total = 0;
	for (int i = 0; i < relations.size(); i++) {
		total += dfs(i, relations);
	}
	return total;
}

int main() {
	vector<string> relations = { 
		"NNNNNN", "YNYNNY", "YNNNNY" , "NNNNNN","YNYNNN","YNNYNN"};
	printf("%ld", totalSalary(relations));
}