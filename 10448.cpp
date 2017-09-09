#include <stdio.h>
#include <algorithm>
#pragma warning(disable:4996)

int T;
int arr[45];
int main() {
	scanf("%d", &T);
	for (int i = 1; i <= 44; i++) {
		arr[i] = i*(i + 1) / 2;
	}
	for (int aa = 0; aa < T; aa++) {
		int K, tmp = 999;
		scanf("%d", &K);
		for (int i = 44; i >= 1; i--) {
			for (int j = 44; j >= 1; j--) {
				for (int k = 44; k >= 1; k--) {
					if (K - arr[i] - arr[j] - arr[k] == 0) {
						tmp = 0;
						break;
					}
				}
				if (tmp == 0)
					break;
			}
			if (tmp == 0)
				break;
		}
		if (tmp == 0)
			printf("1\n");
		else
			printf("0\n");
	}
}