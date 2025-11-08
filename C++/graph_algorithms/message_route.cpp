#include <bits/stdc++.h>

using namespace std;

#define forr(i, r, n) for (int i = r; i < int(n); i++)
#define forn(i, n) forr(i, 0, n)
#define MAXN 100000

struct Path {
	int pi;
	int i;
	int cost;

	const bool operator<(const Path& other) const {
		return cost > other.cost;
	}
};

bool visited[MAXN + 1];
Path mincosts[MAXN + 1];

bool walkfromto(int start, int end, vector<vector<int>>& G) {
	priority_queue<Path> nodes;
	nodes.push({-1, start, 0});
	while (nodes.size()) {
		Path p = nodes.top();
		nodes.pop();
		if (visited[p.i]) {
			continue;
		}
		visited[p.i] = true;
		if (mincosts[p.i].cost == -1 || mincosts[p.i].cost > p.cost) {
			mincosts[p.i] = p;
		}
		if (p.i == end) {
			return true;
		}
		for (auto n : G[p.i]) {
			nodes.push({p.i, n, p.cost + 1});
		}
	}
	return false;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	forn(i, v.size()) os << v[i] << ' ';
	return os;
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> G(N + 1);
	forn(i, M) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	forr(i, 1, N + 1) {
		visited[i] = false;
		mincosts[i].cost = -1;
	}

	if (walkfromto(1, N, G)) {
		Path b = mincosts[N];
		vector<int> path;
		while (b.pi != -1) {
			path.push_back(b.i);
			b = mincosts[b.pi];
		}
		path.push_back(b.i);
		reverse(path.begin(), path.end());
		cout << path.size() << endl
		     << path << endl;
	} else {
		cout << "IMPOSSIBLE" << endl;
	}
}