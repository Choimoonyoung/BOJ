/*#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char A[50];

int main(){
	freopen("input.txt", "r", stdin);
	scanf("%s", A);
	int len = strlen(A);
	sort(A, A + len);
	for (int i = len - 1; i >= 0; i--)printf("%c", A[i]);
}*/
#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;
int N;
char arr[20];

int main(){
	scanf("%s", arr);
	int len = strlen(arr);
	sort(arr,arr+len);
	for (int i = len-1; i >=0; i--){
		printf("%c", arr[i]);
	}
}