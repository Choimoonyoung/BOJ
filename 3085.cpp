#include <stdio.h>
#include <algorithm>
#pragma warning (disable:4996)

int arr[52][52];
int N;
using namespace std;


int count(int i, int j) {
	int max =0;
	for (int a = j; a <= j + 1; a++) {
		for (int b = 1; b <= N; b++) {
			int current = arr[b][a];
			int sum=0;
			for (int x = b, y = a; x <= N && arr[x][y] == current; x++, sum++);
			if (max < sum)
				max = sum;
		}
	}

	for (int a = 1; a < N; a++) {
		int current = arr[i][a];
		int sum = 0;
		for (int x = i, y = a; y <= N && arr[x][y] == current; y++, sum++);
		if (max < sum)
			max = sum;
	}

	return max;
}


int count2(int i, int j) {
	int max=0;
	for (int a = i; a <= i + 1; a++) {
		for (int b = 1; b <= N; b++) {
			int current = arr[a][b];
			int sum = 0;
			for (int x = a, y = b; y <= N && arr[x][y] == current; y++, sum++);
			if (max < sum)
				max = sum;
		}
	}

	for (int a = 1; a < N; a++) {
		int current = arr[a][j];
		int sum = 0;
		for (int x = a, y = j; x<= N && (arr[x][y] == current); x++, sum++);
		if (max < sum)
			max = sum;
	}
	return max;
}

int main() {
	scanf("%d", &N);
	int max = 0;
	for (int i = 1; i <= N; i++) {
		char str[52];
		scanf("%s", str);
		getchar();
		for (int j = 1; j <= N; j++) {
			arr[i][j] = str[j - 1];
		}
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int tmp, max1=0, max2=0;
			if (j + 1 <= N) {
				tmp = arr[i][j];
				arr[i][j] = arr[i][j + 1];
				arr[i][j + 1] = tmp;

				max1 = count(i, j);

				tmp = arr[i][j];
				arr[i][j] = arr[i][j + 1];
				arr[i][j + 1] = tmp;
			}

			if (i + 1 <= N) {
				tmp = arr[i][j];
				arr[i][j] = arr[i + 1][j];
				arr[i + 1][j] = tmp;

				max2 = count2(i, j);

				tmp = arr[i][j];
				arr[i][j] = arr[i + 1][j];
				arr[i + 1][j] = tmp;
			}
			if (max1 >= max2 && max1 >= max)
				max = max1;
			else if (max2 >= max1 && max2 >= max)
				max = max2;
			else;
		}
	}
	printf("%d", max);
}

/*for (int count = 0; count <= 1; count++) {
				int sum = 0;
				for (int dir = -1; dir <= 1; dir += 2)
					for (int x = i + count, y = j + dir; x >= 1 && x <= N && y <= N && y >= 1; y += dir) {
						if (arr[x][y] == arr[i + count][j])
							sum++;
						else break;
						}*/

/*for (int x = i + 2 * count - 1, y = j; x >= 1 && x <= N && y >= 1 && y <= N; x += 2 * count - 1) {
					if (arr[x][y] == arr[i + count][j])
						sum2++;
					else break;
					}*/