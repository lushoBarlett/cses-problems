#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>

using namespace std;
using Coord = pair<int,int>;

constexpr int MAXN = 1e3;
constexpr int MOD = 1e9 + 7;

int DP[MAXN][MAXN];

int paths(vector<vector<bool>>& grid, Coord here = {0,0}) {
	if (here.first >= grid.size() or here.second >= grid.size() or
	    !grid[here.first][here.second])
		return 0;

	if (DP[here.first][here.second] != -1)
		return DP[here.first][here.second];

	return DP[here.first][here.second] =
	    (paths(grid, {here.first + 1, here.second}) +
	     paths(grid, {here.first, here.second + 1})) % MOD;
}

int main() {
	int N;
	cin >> N;
	vector<vector<bool>> grid;
	grid.resize(N);
	getchar(); // newline
	for(int i = 0; i < N; i++) {
		grid[i].resize(N);
		for(int j = 0; j < N; j++) {
			grid[i][j] = getchar() == '.';
			DP[i][j] = -1;
		}
		getchar(); // newline
	}
	DP[N-1][N-1] = 1;
	cout << paths(grid) << endl;
}
