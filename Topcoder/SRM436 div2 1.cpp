#include <algorithm>
#include <vector>

using namespace std;

int visit[30];

int dfs(int i, int count, int depth, vector<string> friends) {
	if (visit[i] == 1 || depth == 2)
		return count;
	visit[i] = 1;
	for (int j = 0; j < friends.size(); j++) {
		if (friends[i][j] == 'Y' && visit[j] ==0) {
			count = dfs(j, count + 1, depth + 1, friends);
		}
	}
	return count;
}

int highestScore(vector<string> friends) {
	int ans = 0;
	for (int i = 0; i < friends.size(); i++) {
		int tmp = dfs(i, 0, 0 ,friends);
		ans = max(tmp, ans);
		for (int k = 0; k < friends.size(); k++)
			visit[k] = 0;
	}
	return ans;
}

int main() {
	vector<string> a = { "NNNNYNNNNN",
		"NNNNYNYYNN",
		"NNNYYYNNNN",
		"NNYNNNNNNN",
		"YYYNNNNNNY",
		"NNYNNNNNYN",
		"NYNNNNNYNN",
		"NYNNNNYNNN",
		"NNNNNYNNNN",
		"NNNNYNNNNN" };
	printf("%d", highestScore(a));
}