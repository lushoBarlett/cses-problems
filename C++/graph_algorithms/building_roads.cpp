#include <bits/stdc++.h>

using namespace std;

#define forr(i, r, n) for (int i = r; i < int(n); i++)
#define forn(i, n) forr(i, 0, n)

void flood(int i, vector<vector<int>>& G, vector<bool>& visited) {
	for (auto n : G[i]) {
		if (!visited[n]) {
			visited[n] = true;
			flood(n, G, visited);
		}
	}
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

	vector<int> hubs;
	vector<bool> visited(N+1, false);
	forr(i, 1, N+1) {
		if (!visited[i]) {
			visited[i] = true;
			hubs.push_back(i);
			flood(i, G, visited);
		}
	}
	assert(hubs.size() > 0);
	cout << hubs.size() - 1 << endl;
	auto prev = hubs.begin();
	for (auto it = next(prev); it != hubs.end(); it++) {
		cout << *prev << ' ' << *it << endl;
		prev = it;
	}
}