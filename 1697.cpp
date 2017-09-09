#include<stdio.h>
#include<queue>

using namespace std;
queue<int> Q;
int N, K;

int find(int count) {
	for (int i = 0; i < 3*count; i++) {
		int now = Q.front();
		if (now == K)
			return count;
		Q.pop();
		find(count + 1);
	}
}
int main() {
	scanf("%d %d", &N, &K);
	Q.push(N);
	printf("%d",find(0));
}