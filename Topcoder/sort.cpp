#include<stdio.h>

int arr[8] = { 8,4,1,7,11,13,5,2 };

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
		for (j = i - 1; j >= 0, arr[j] > ptr ; j--) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = ptr;
	}
}

int main() {
	insertionsort();
	for (int i = 0; i < 8; i++) {
		printf("%d ", arr[i]);
	}
}