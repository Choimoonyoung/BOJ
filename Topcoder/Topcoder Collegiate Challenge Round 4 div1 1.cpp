#include <algorithm>
#include <vector>
#include <map>
using namespace std;
/*typedef struct coord {
	int x, y;
	int depth;
}Coord;

int dy[16] = { 0,1,1,1,0,-1,-1,-1,1,2,2,1,-1,- 2,-2,-1 };
int dx[16] = { -1,-1,0,1,1,1,0,-1,-2,-1,1,2,2,1,-1,-2 };
int dp[101][101][51];

int dfs(Coord cur, int depth, Coord end, int size) {
	if (depth == 0 && end.x == cur.x && end.y == cur.y)
		return 1;
	if (depth == 0)
		return 0;
	if (dp[cur.x][cur.y][depth] != 0)
		return dp[cur.x][cur.y][depth];
	int count = 0;
	for (int i = 0; i < 16; i++) {
		int nx = cur.x+dx[i];
		int ny = cur.y+dy[i];
		if (nx < 0 || nx >= size || ny < 0 || ny >= size) continue;
		Coord next = { nx,ny,depth - 1 };
		count += dfs(next, depth - 1, end,size);
	}
	return dp[cur.x][cur.y][depth] = count;
}
long howMany(int size, vector<int> start, vector <int> end, int numMoves) {
	Coord start1= { start[0],start[1],0 };
	Coord end1 = { end[0],end[1],0 };
	return dfs(start1, numMoves,end1,size);
}
*/

int dy[16] = { 0,1,1,1,0,-1,-1,-1,1,2,2,1,-1,-2,-2,-1 };
int dx[16] = { -1,-1,0,1,1,1,0,-1,-2,-1,1,2,2,1,-1,-2 };
long long board[100][100][51] = { 0 };

long long howMany(int size, vector<int> start, vector <int> end, int numMoves) {
	board[start[0]][start[1]][0] = 1;
	for (int num = 1; num <= numMoves; num++) {
		for (int x = 0; x < size; x++) {
			for (int y = 0; y < size; y++) {
				for (int i = 0; i < 16; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (nx < 0 || nx >= size || ny < 0 || ny >= size) continue;
					board[x][y][num] += board[nx][ny][num - 1];
				}
			}
		}
	}
	return board[end[0]][end[1]][numMoves];
}

int main() {
	vector<int> start = { 0,0 };
	vector<int> end = { 0,99};
	int numMoves = 50;
	int size = 100;
	printf("%lld\n", howMany(size,start,end,numMoves));
}