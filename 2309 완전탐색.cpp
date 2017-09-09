#include <stdio.h>
#include <algorithm>
#pragma warning(disable:4996)


using namespace std;

int main() {
	int arr[9];
	int tmp;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &tmp);
		arr[i] = tmp;
	}

	int sum = 0;
	for (int i = 0; i < 9; i++) {
		sum += arr[i];
	}
	sum -= 100;

	int no1, no2;
	for (no1 = 0; no1 < 9; no1++) {
		for (no2 = no1+1; no2 < 9; no2++) {
			if (sum == arr[no1] + arr[no2]) {
				tmp = -1;
				break;
			}
		}
		if (tmp == -1)
			break;
	}
	no1 = arr[no1];
	no2 = arr[no2];
	sort(arr, arr + 9);
	for (int i = 0; i < 9; i++) {
		if (arr[i] != no1 && arr[i] != no2)
			printf("%d\n", arr[i]);
	}

}