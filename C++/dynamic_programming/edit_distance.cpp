#include <iostream>
#include <vector>
#include <string>

using namespace std;

constexpr int MAXN = 5e3;

int DP[MAXN][MAXN];

int dist(string& a, string& b, int until_a, int until_b) {
	// comparison with empty string
	if (until_a < 0)
		return until_b + 1;
	if (until_b < 0)
		return until_a + 1;

	if (DP[until_a][until_b] != -1)
		return DP[until_a][until_b];

	int x = dist(a, b, until_a - 1, until_b) + 1;
	int y = dist(a, b, until_a, until_b - 1) + 1;
	int z = dist(a, b, until_a - 1, until_b - 1) + int(a[until_a] != b[until_b]);

	return DP[until_a][until_b] = min(min(x, y), z);
}

int main() {
	string a, b;
	cin >> a >> b;
	for(int i = 0; i < a.size(); i++)
		for(int j = 0; j < b.size(); j++)
			DP[i][j] = -1;
	cout << dist(a, b, a.size() - 1, b.size() - 1) << endl;
}
