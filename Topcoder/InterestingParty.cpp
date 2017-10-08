#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int interestingParty(vector<string> first, vector<string> second) {
	map<string, int> hobby;
	map<string, int>::iterator hobbyPos;
	for (int i = 0; i < first.size(); i++) {
		hobby[first[i]] = 0;
		hobby[second[i]] = 0;
	}
	for (int i = 0; i < first.size(); i++) {
		hobby[first[i]]++;
		hobby[second[i]]++;
	}

	int max1 = 0;
	for (hobbyPos = hobby.begin(); hobbyPos != hobby.end(); ++hobbyPos) {
		max1 = max(max1, hobbyPos->second);
	}
	return max1;
}

int bestInvitation(vector<string> first, vector<string> second) {
	int ans = 0;
	for (int i = 0; i < first.size(); i++){
		int tmp = 0;
		int tmp2 = 0;
		for (int idx = i; idx < first.size(); idx++) {
			if (first[i] == first[idx]) tmp++;
			else if (first[i] == second[idx]) tmp++;
			if (second[i] == first[idx]) tmp2++;
			else if (second[i] == second[idx]) tmp2++;
		}
		tmp = max(tmp, tmp2);
		ans = max(tmp, ans);
	}
	return ans;
}
int main() {
	vector<string> first = { "variety", "diversity", "loquacity", "courtesy" };
	vector<string> second = { "talking", "speaking", "discussion", "meeting" };
	printf("%d",bestInvitation(first, second));
}