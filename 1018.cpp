#include <stdio.h>
#pragma warning (disable:4996)

int M, N;
char arr[51][51];
char color[2] = { 'B','W' };

int main() {
	int result = 99999;
	scanf("%d %d", &M, &N);
	char s[51];
	getchar();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr[i][j] = getchar();
		}
		getchar();
	}
	int cdx = 0;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			int count = 0;
			for (int x = i; x < i + 8; x++) {
				for (int y = j; y < j + 8; y++) {
					bool a = (arr[x][y] == color[(cdx++) % 2]);
					if (a == false)
						count++;
				}
				cdx--;
			}
			if (count > 64 - count)
				count = 64 - count;
			if (count < result)
				result = count;
		}
	}

	printf("%d", result);
}

/*	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			int count = 0;
			int currentp = i + j;
			int cidx = 0;
			for (int th = currentp; th < 16 + currentp; th++) {
				if (th < 8+currentp) {
					for (int x = th - j; x >= i; x--) {
						bool result = (color[cidx % 2] == arr[th - x][x]);
						if (result == false)
							count++;
					}
				}
				else {
					for (int x = j + 7; th - x < i + 8; x--) {
						bool result = (color[cidx % 2] == arr[x][th-x]);
						if (result == false)
							count++;
					}
				}
				cidx++;
			}
			if (count > 64 - count)
				count = 64 - count;
			if (result > count)
				result = count;
		}
		}*/