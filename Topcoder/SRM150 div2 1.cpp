#include <algorithm>
#include <vector>

using namespace std;

/*vector<int> digits(int base) {
	vector<int> numbers;
	for (int num = 2; num < base; num++) {
		int tmp = 0;
		for (int i = 2; i < pow(base, 4) - 1; i++) {
			int check = num * i;
			int sum = 0;
			for (; check != 0; check /= base) {
				sum += (check % base);
			}
			if (sum % num != 0) {
				tmp = 1; //¸ÁÇÔ
				break;
			}
		}
		if(tmp ==0)
			numbers.push_back(num);
	}
	return numbers;
} */ //1

/*vector<int> digits(int base) {
	vector<int> numb;
	for (int num = 2; num < base; num++) {
		int tmp = 0;
		for (int i = 0; i < base; i++) { //1
			for (int j = 0; j < base; j++) { // 2
				for (int k = 0; k < base; k++) { //3
					int total = pow(base, 2)*i + base* j + k;
					if (total % num == 0 && (i + j + k) % num != 0) {
						tmp = 1;
						break;
					}
				}
				if (tmp == 1)break;
			}
			if (tmp == 1)break;
		}
		if (tmp == 0) numb.push_back(num);
	}
	return numb;
}*/

vector<int> digits(int base) {
	int total = base - 1;
	vector<int> k;
	for (int i = 2; i < base; i++) {
		if (total%i == 0) k.push_back(i);
	}
	return k;
}
int main() {
	vector<int> a = digits(30);
	for (int i = 0; i<a.size(); i++)
		printf("%d", a[i]);
}