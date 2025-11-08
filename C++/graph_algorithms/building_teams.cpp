#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000
#define forr(i, r, n) for (int i = r; i < int(n); i++)
#define forn(i, n) forr(i, 0, n)

enum Color : uint8_t {
	NONE = 0,
	RED = 1,
	BLUE = 2,
};

Color color[MAXN+1];

Color other(Color c) {
	switch (c) {
		case NONE: return NONE;
		case RED: return BLUE;
		case BLUE: return RED;
	}
	assert(false);
}

bool twocolor(int n, Color c, vector<vector<int>>& G) {
	if (color[n] != NONE) return color[n] == c;
	color[n] = c;
	for (auto nn : G[n])
		if (!twocolor(nn, other(c), G))
			return false;
	return true;
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> G(N+1);

	forn(i, M) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	forr(i, 1, N+1) {
		color[i] = NONE;
	}

	forr(i, 1, N+1) {
		if (color[i] == NONE && !twocolor(i, RED, G)) {
			cout << "IMPOSSIBLE" << endl;
			exit(0);
		}
	}
	forr(i, 1, N+1) {
		assert(color[i] != NONE);
		cout << (int)color[i] << ' ';
	}
	cout << endl;
}