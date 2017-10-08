#include <algorithm>
#include <vector>

using namespace std;
vector<int> dx = {1,-1,0,0};
vector <int> dy = { 0,0,-1,1 };
vector <double> percent;
bool visit[29][29] = { false };

double dfs(int x, int y, int depth) {
	if (visit[x][y])
		return 0;
	if (depth == 0)
		return 1;
	visit[x][y] = true;
	double prob = 0.0;
	for (int i = 0; i < 4; i++) {
		prob += dfs(x + dx[i], y + dy[i], depth-1)* percent[i];
	}
	visit[x][y] = false;
	return prob;
}
double getProbability(int n, int east, int west, int south, int north) {
	percent.push_back(east*0.01);
	percent.push_back(west*0.01);
	percent.push_back(south*0.01);
	percent.push_back(north*0.01);

	return dfs(n, n, n);
}

int main() {
	printf("%f", getProbability(14, 25, 25, 25, 25));
}