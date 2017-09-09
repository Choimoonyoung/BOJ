#include<stdio.h>
#include<math.h>
#pragma warning(disable:4996)

int ant[1000002];

int main(){
	int T;
	scanf("%d", &T);//test case
	for (int i = 1; i <= T; i++){
		int len, size;
		scanf("%d %d", &len, &size);
		for (int i = 0; i < size; i++)
			scanf("%d", &ant[i]);
		int min = len;
		int max = 0;
		int realmin=0;
		for (int i = 0; i < size; i++){
			if (ant[i] < min)
				min = ant[i];
			if (ant[i] > max)
				max = ant[i];
			if (fabs(double(len) / 2.0 - ant[i]) < fabs(double(len) / 2.0 - ant[realmin]))
				realmin = i;
		}
		int realmax;
		if (max > len - min)
			realmax = max;
		else
			realmax = len - min;
		if (ant[realmin] > double(len) / 2.0)
			realmin = len - ant[realmin];
		else
			realmin = ant[realmin];
		printf("%d %d\n", realmin, realmax);
	}
}