#include <algorithm>
#include <vector>

using namespace std;

long long encrypt1(vector<int> numbers) {
	long long result = 0;
	for (int i = 0; i < numbers.size(); i++) {
		long long plusnum = 1;
		for (int j = 0; j < numbers.size(); j++) {
			if (i == j)
				plusnum *= (numbers[j] + 1);
			else
				plusnum *= numbers[j];
		}
		result = max(plusnum, result);
	}
	return result;
}

long long encrypt(vector<int> numbers) {
	sort(numbers.begin(), numbers.end());
	long long result = numbers[0]+1;
	for (int i = 1; i < numbers.size(); i++) {
		result *= numbers[i];
	}
	return result;
}

int main() {

}