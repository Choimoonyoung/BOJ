#include<stdio.h>
#include<math.h>
#pragma warning(disable:4996)

int arr[8] = { 8,4,1,7,11,13,5,2 };
char* arr2 = "hi";

void bubblesort() {
	int tmp;
	for (int i = 49; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

void insertionsort() {
	for (int i = 1; i < 8; i++) {
		int ptr = arr[i];
		int j;
		for (j = i - 1; j >= 0 && arr[j] > ptr;j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = ptr;
	}
}

int length(int idx) {
	if (arr2[idx] == '\0')
		return 0;
	return 1 + length(idx + 1);
}

void printarr(int idx) {
	if (arr2[idx] == '\0')
		return;
	printarr(idx + 1);
	printf("%c", arr2[idx]);
}

void binaryChange(int n) {
	if (n == 0)
		return;
	binaryChange(n / 2);
	printf("%d", n % 2);
}

int sumOfArr(int len, int idx) {
	if (len <= 0)
		return 0;
	return arr[idx] + sumOfArr(len - 1 , idx+1);
}

int findMax(int begin, int end) {
	if (begin == end)
		return arr[begin];
	int middle = begin + end / 2;
	int max1 = findMax(begin, middle);
	int max2 = findMax(middle + 1, end);
	if (max1 > max2)
		return max1;
	else return max2;
}

int main() {
	printf("%d", sumOfArr(8, 0));
}