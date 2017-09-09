#include <stdio.h>
#include <algorithm>
#pragma warning (disable:4996)

int N, count, num[3], arr[3];

int main() {
	scanf("%d", &N);
	for (int a = 0; a < N; a++) {
		int test, strike, ball;
		for (int i = 2; i >= 0; i--) {
			num[i] = test % 10;
			test /= 10;
		}

		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				for (int k = 1; k <= 9; k++) {
					if (i == j || j == k || k == i) continue;
					arr[0] = i, arr[1] = j, arr[2] = k;
					int x=0, y =0;
					for(int idx= 0;idx<=2;idx++){
						if (num[idx] == arr[idx]) x++;
						else if(num[idx] = arr[(idx+1)%3])
					}
				}
			}
		}
	}
}






/* ³» ÄÚµå

int ball[101], strike[101], arr[101], check[3];


int main() {
	int count=0, tmp=0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &arr[i],&strike[i], &ball[i]);
	}

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			for (int k = 1; k <= 9; k++) {
				if (i == j || j == k || k == i)
					continue;

				//strike
				for (int idx = 0; idx < N; idx++) {
					check[0] = arr[idx]/100 - i;
					check[1] = (arr[idx] / 10)%10 - j;
					check[2] = arr[idx] % 10 - k;

					int sum = 0;
					for (int a = 0; a <= 2; a++) {
						if (check[a] == 0)
							sum++;
					}

					if (sum == strike[idx]) {
						sum = 0;
						check[0] = arr[idx] / 100;
						check[1] = (arr[idx] / 10) % 10;
						check[2] = arr[idx] % 10;
						if (check[0] - i == 0 || check[0] - j == 0 || check[0] - k == 0)
							sum++;
						if (check[1] - i == 0 || check[1] - j == 0 || check[1] - k == 0)
							sum++;
						if (check[2] - i == 0 || check[2] - j == 0 || check[2] - k == 0)
							sum++;

						if (sum == (ball[idx] + strike[idx])) {
							tmp = 1;
						}
						else {
							tmp = 0;
							break;
						}
					}
					else { 
						tmp = 0;
						break;
					}
				}
				if (tmp == 1) {
					count++; tmp = 0;
				}

			}
		}
	}
	printf("%d", count);
}*/