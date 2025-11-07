#include <bits/stdc++.h>

using namespace std;

#define forr(i, r, n) for (int i = r; i < int(n); i++)
#define forn(i, n) forr(i, 0, n)
#define MAXN 1000

bool walkable[MAXN][MAXN];

void flood(int i, int j, int N, int M) {
	if (i < 0 || i >= N || j < 0 || j >= M) return;
	if (!walkable[i][j]) return;

	walkable[i][j] = false;

	flood(i - 1, j, N, M);
	flood(i + 1, j, N, M);
	flood(i, j - 1, N, M);
	flood(i, j + 1, N, M);
}

int main() {
	int N, M;
	cin >> N >> M;
	forn(i, N) forn(j, M) {
		char c;
		cin >> c;
		walkable[i][j] = c == '.';
	}

	size_t rooms = 0;
	forn(i, N) forn(j, M) {
		if (walkable[i][j]) {
			flood(i, j, N, M);
			rooms++;
		}
	}

	cout << rooms << endl;
}