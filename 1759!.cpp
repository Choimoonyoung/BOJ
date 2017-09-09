#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

char arr[17];
int L;
int C;
char* vow = "aeiou";


void heapdown(char* a, int endidx, int idx){
	if (idx > endidx || 2 * idx + 1>endidx)
		return;
	int maxidx = 2 * idx + 1;
	if (2 * idx + 2 <= endidx && a[maxidx] < a[maxidx + 1])
		maxidx++;
	if (a[idx] < a[maxidx]){
		int temp = a[idx];
		a[idx] = a[maxidx];
		a[maxidx] = temp;
	}
	heapdown(a, endidx, maxidx);
}

void heapup(char* a, int idx){
	if (idx <= 0)
		return;
	int parent = (idx - 1) / 2;
	if (a[parent] < a[idx]){
		char tmp = a[parent];
		a[parent] = a[idx];
		a[idx] = tmp;
		heapup(a, parent);
	}
}

void makeheap(char* a){
	for (int i = 1; i < C; i++){
		heapup(a, i);
	}
}

char* heapsort(char*a){
	makeheap(a);
	for (int i = C - 1; i > 0; i--){
		int temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		heapdown(a, i - 1, 0);
	}
	return a;
}


void one(int start, int left, char * a){
	int len = strlen(a);
	if (left ==0){
		int tmp = 0;
		for (int i = 0; i <= L-1; i++){
			if (strchr("aeiou", a[i]) != NULL)
				tmp++; // 모음이 하나라도 있으면
		}
		if (tmp >= 1 && L - tmp >= 2)
			printf("%s\n", a);
		return;
	}
	for (int i = start; i <= C-left; i++){
		a[L - left] = arr[i];
		one(i + 1, left - 1, a);
	}
}

int main(){
	scanf("%d %d", &L, &C);
	char temp;
	getchar();
	for (int i = 0; i < C; i++){
		scanf("%c", &arr[i]);
		scanf("%c", &temp);
	}
	heapsort(arr);
	char* a = (char*)malloc(sizeof(char)*(L+1));
	a[L] = NULL;
	one(0, L, a);
}