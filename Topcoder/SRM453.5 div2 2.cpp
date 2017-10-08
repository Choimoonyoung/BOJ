#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef struct coord {
	int x, y, depth;
}Coord;

bool board[50][50] = { false };

int longestPath(vector<string> maze, int startRow, int startCol, vector <int> moveRow, vector<int> moveCol) {
	for (int i = 0; i < maze.size(); i++)
		for (int j = 0; j < maze[0].size(); j++)
			if (maze[i][j] == '.') board[i][j] = true;

	int ans = 0;
	queue<Coord> Q;
	Coord first = { startRow, startCol, 0 };
	board[startRow][startCol] = false;
	Q.push(first);

	for (; !Q.empty();) {
		Coord cur = Q.front();
		Q.pop();
		ans = max(ans, cur.depth);
		for (int i = 0; i < moveRow.size(); i++) {
			int nx = cur.x + moveRow[i];
			int ny = cur.y + moveCol[i];
			if (nx < maze.size() && ny < maze[0].size() && board[nx][ny] == true) {
				board[nx][ny] = false;
				Q.push({ nx,ny,cur.depth + 1 });
			}
		}
	}
	for (int i = 0; i < maze.size(); i++)
		for (int j = 0; j < maze[0].size(); j++)
			if (board[i][j] == true)
				return -1;
	return ans;

}

int main() {

}