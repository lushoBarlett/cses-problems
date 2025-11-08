#include <bits/stdc++.h>

using namespace std;

#define forr(i, r, n) for (int i = r; i < int(n); i++)
#define forn(i, n) forr(i, 0, n)
#define MAXN 100000

bool visited[MAXN+1] = {false};
vector<vector<int>> G(MAXN+1);
vector<int> path;

bool dfs(int i, int pi) {
	if (visited[i]) {
		path.push_back(i); // im a cicle
		return true;
	}
	visited[i] = true;
	for (auto n : G[i]) {
		if (n != pi && dfs(n, i)) { // im not "returning", and that way is a cycle
			path.push_back(i); // im part of the cicle
			if (*path.rbegin() == *path.begin()) { // the cycle is complete, print now and exit
				cout << path.size() << endl;
				for (auto n : path) cout << n << ' ';
				cout << endl;
				exit(0);
			}
			return true;
		}
	}
	return false;
}

int main() {
	int N, M, a, b;
	cin >> N >> M;
	forn(i, M) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	forr(i, 1, N+1) visited[i] = false;
	forr(i, 1, N+1) {
		if (!visited[i]) dfs(i, -1);
	}
	cout << "IMPOSSIBLE" << endl;
}