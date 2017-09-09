#include <stdio.h>
#pragma warning(disable:4996)

int N, x, y;

int tournament(){
	int count = 0;
	for (;;){
		if (x == y)
			break;
		count++;
		if (x % 2 == 1)
			x = (x + 1) / 2;
		else
			x = x / 2;
		if (y % 2 == 1)
			y = (y + 1) / 2;
		else
			y = y / 2;
	}
	return count;
}

int main(){
	scanf("%d %d %d", &N, &x, &y);
	if (x > N || y > N || x < 1 || y < 1)
		printf("-1");
	else
		printf("%d", tournament());
}