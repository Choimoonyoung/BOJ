#include <vector>

using namespace std;

/*int theNumber(string answer) {
	int begin = 0, end = 15;
	for (int i = 0; i < 4; i++) {
		if (answer[i] == 'Y')
			begin = (begin + end) / 2;
		else
			end = (begin + end) / 2 + 1;
	}
	return begin;
}*/

/*int theNumber(string answer) {
	string c[4] = {
		"YYYYYYYYNNNNNNNN",
		"YYYYNNNNYYYYNNNN",
		"YYNNYYNNYYNNYYNN",
		"YNYNYNYNYNYNYNYN"
	};

	for (int i = 0; i < 16; i++) {
		bool tmp = true;
		for (int j = 0; j < 4; j++) {
			if (c[j][i] != answer[j]) {
				tmp = false;
				break;
			}
		}
		if (tmp == true)
			return i + 1;
	}
}*/

int theNumber(string answer) {
	int ans = 1;
	int mult = 8;
	for (int i = 0; i < 4; i++) {
		if (answer[i] == 'N')
			ans += mult;
		mult /= 2;
	}
	return ans;

}