#include<stdio.h>
#include<algorithm>
#include<stdlib.h>

using namespace std;
int arr[10002] = { 0 };
int N;

int main(){
	scanf("%d", &N);
	int k;
	for (int i = 0; i < N; i++){
		scanf("%d", &k);
		arr[k]++;
	}
	for (int i = 1; i < 10001; i++){
		if (arr[i] != 0)
			for (int j = 0; j < arr[i]; j++)
				printf("%d\n", i);
	}
}