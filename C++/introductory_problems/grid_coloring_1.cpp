#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 500;

string grid[MAXN];

char coloring1(int i, int j) {
	return (i + j) % 2 ? 'A' : 'B';
}

char coloring2(int i, int j) {
	return (i + j) % 2 ? 'C' : 'D';
}

char restriction(int i, int j) {
	return grid[i][j];
}

char color(int i, int j) {
	char c1 = coloring1(i, j);
	char c2 = coloring2(i, j);
	char r = restriction(i, j);

	return c1 == r ? c2 : c1;
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> grid[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << color(i, j);
		cout << endl;
	}
}