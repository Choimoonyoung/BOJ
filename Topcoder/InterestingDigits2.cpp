#include <algorithm>
#include <vector>

using namespace std;

vector<int> digits(int base) {
	vector<int> numbers;
	for (int num = 2; num < base; num++) {
		for (int i = 2; i < pow(base, 5) - 1; i++) {
			int check = num * i;
			int sum = 0;
			for (; check != 0; check /= base) {
				sum += (check % base);
			}
			if (sum % num != 0)
				break;
		}
		numbers.push_back(num);
	}
	return numbers;
}

int main() {
	vector<int> a = digits(10);
	for(int i = 0 ; i<a.size();i++)
		printf("%d", a[i]);
}