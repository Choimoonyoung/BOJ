#include <vector>
#include <string>

using namespace std;

/*int find(string s) {
	char end = s.back();
	for (int i = 0; i < s.size(); i++) {
		bool a = true;
		if (s[i] == end) {
			for (int k = i, j = s.size() - 1; j > k; k++,j--) {
				if (s[k] != s[j]) {
					a = false;
					break;
				}		
			}
			if (a == true)
				return i+s.size();
		}
	}
}*/

int find(string s) {
	for (int i = s.size(); i < s.size() * 2; i++) {
		bool a = true;
		for (int j = 0; j < i / 2; j++) {
			if (i - j - 1 < s.size() && s[j] != s[i - j - 1]) {
				a = false;
				break;
			}
		}
		if (a == true) return i;
	}
	return 0;
}
int main() {
	string s = "abab";
	printf("%d", find(s));
}