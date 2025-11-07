#include <bits/stdc++.h>

using namespace std;

#define forr(i, r, n) for (int i = r; i < n; i++)
#define forn(i, n) forr(i, 0, n)
#define MAXN 1000

enum Direction : uint8_t {
	DIAG = 0,
	DOWN = 1,
	RIGHT = 2
};

struct Path {
	int lcs;
	Direction dir;

	const bool operator<(const Path& other) const {
		return lcs < other.lcs;
	}
};

Path DP[MAXN + 1][MAXN + 1];

Path lcs(size_t i, size_t j, vector<int>& a1, vector<int>& a2) {
	if (DP[i][j].lcs != -1) return DP[i][j];

	if (i >= a1.size() || j >= a2.size()) return DP[i][j] = {0, DIAG};

	if (a1[i] == a2[j]) {  // always convenient to grab ASAP
		auto inc = lcs(i + 1, j + 1, a1, a2);
		return DP[i][j] = {inc.lcs + 1, DIAG};
	} else {
		auto left = lcs(i + 1, j, a1, a2);
		auto right = lcs(i, j + 1, a1, a2);
		if (left < right) {
			return DP[i][j] = {right.lcs, RIGHT};
		} else {
			return DP[i][j] = {left.lcs, DOWN};
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> array1(N), array2(M);
	forn(i, N) cin >> array1[i];
	forn(i, M) cin >> array2[i];
	forn(i, N + 1) forn(j, M + 1) DP[i][j] = {-1, DIAG};
	/**
	 * lcs(i, j) =
	 *   max {
	 *     1 + lcs(i + 1, j + 1) [if array1[i] == array2[i]]
	 *     lcs(i + 1, j),
	 *     lcs(i, j + 1),
	 *   }
	 */
	Path result = lcs(0, 0, array1, array2);
	cout << result.lcs << endl;
	for (size_t i = 0, j = 0; i < array1.size() && j < array2.size() && DP[i][j].lcs > 0;) {
		switch (DP[i][j].dir) {
			case DIAG:
				cout << array1[i] << ' ';
				i++;
				j++;
				break;
			case DOWN:
				i++;
				break;
			case RIGHT:
				j++;
				break;
		}
	}
	cout << endl;
}