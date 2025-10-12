#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1000;

int16_t board[MAXN][MAXN];

struct Move {
	int moves, i, j;
};

void knight_bfs(int n, int moves = 0, int i = 0, int j = 0) {
	queue<Move> nodes;
	nodes.push({moves, i, j});

	while (nodes.size()) {
		Move m = nodes.front();
		nodes.pop();

		moves = m.moves;
		i = m.i;
		j = m.j;

		if (i < 0 || j < 0 || i > n || j > n)  // out of bounds
			continue;

		if (board[i][j] != -1)  // visited
			continue;

		board[i][j] = moves;  // visit

		// 8 knight moves
		// choose + or -, choose 1-2 or 2-1, choose + or -
		nodes.push({moves + 1, i + 1, j + 2});
		nodes.push({moves + 1, i + 2, j + 1});

		nodes.push({moves + 1, i + 1, j - 2});
		nodes.push({moves + 1, i + 2, j - 1});

		nodes.push({moves + 1, i - 1, j + 2});
		nodes.push({moves + 1, i - 2, j + 1});

		nodes.push({moves + 1, i - 1, j - 2});
		nodes.push({moves + 1, i - 2, j - 1});
	}
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			board[i][j] = -1;

	knight_bfs(N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
}