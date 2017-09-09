#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	int N;
	int min = 0;
	scanf("%d", &N);
	for (int i = N - 1; i > N - 54 && i>0; i--) {
		int tmp = i;
		int sum = i;
		while (tmp > 0) {
			sum += tmp % 10;
			tmp /= 10;
		}
		if (sum == N)
			min = i;
	}
	printf("%d", min);
}