#include <bits/stdc++.h>

using namespace std;

#define forr(i, r, n) for (int i = r; i < int(n); i++)
#define forn(i, n) forr(i, 0, n)
#define MAXN 1000

struct Path {
	int pi;
	int pj;
	int i;
	int j;
	int cost;

	const bool operator<(const Path& other) const {
		return cost > other.cost;
	}
};

bool walkable[MAXN][MAXN];
Path mincosts[MAXN][MAXN];

bool walkfromto(int Ai, int Aj, int Bi, int Bj, int N, int M) {
	priority_queue<Path> nodes;
	nodes.push({ -1, -1, Ai, Aj, 0 });
	while (nodes.size()) {
		Path p = nodes.top(); nodes.pop();
		if (p.i < 0 || p.i >= N || p.j < 0 || p.j >= M || !walkable[p.i][p.j]) {
			continue;
		}
		walkable[p.i][p.j] = false;
		if (mincosts[p.i][p.j].cost == -1 || mincosts[p.i][p.j].cost > p.cost) {
			mincosts[p.i][p.j] = p;
		}
		if (p.i == Bi && p.j == Bj) {
			return true;
		}
		nodes.push({ p.i, p.j, p.i - 1, p.j, p.cost + 1});
		nodes.push({ p.i, p.j, p.i + 1, p.j, p.cost + 1});
		nodes.push({ p.i, p.j, p.i, p.j - 1, p.cost + 1});
		nodes.push({ p.i, p.j, p.i, p.j + 1, p.cost + 1});
	}
	return false;
}

int main() {
	int N, M, Ai, Aj, Bi, Bj;
	cin >> N >> M;
	forn(i, N) forn(j, M) {
		char c;
		cin >> c;
		walkable[i][j] = c == '.' || c == 'A' || c == 'B';
		mincosts[i][j].cost = -1;
		if (c == 'A') {
			Ai = i;
			Aj = j;
		} else if (c == 'B') {
			Bi = i;
			Bj = j;
		}
	}

	if (walkfromto(Ai, Aj, Bi, Bj, N, M)) {
		Path b = mincosts[Bi][Bj];
		string ops;
		while (b.i != Ai || b.j != Aj) {
			if (b.pi < b.i) {
				ops.push_back('D');
			} else if (b.pi > b.i) {
				ops.push_back('U');
			} else if (b.pj < b.j) {
				ops.push_back('R');
			} else if (b.pj > b.j) {
				ops.push_back('L');
			}
			b = mincosts[b.pi][b.pj];
		}
		reverse(ops.begin(), ops.end());
		cout << "YES" << endl << ops.size() << endl << ops << endl;
	} else {
		cout << "NO" << endl;
	}
}