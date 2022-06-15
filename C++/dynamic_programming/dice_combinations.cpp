#include <iostream>
#include <vector>
#include <string>

using namespace std;

constexpr int MAXN = 1e6 + 1;
constexpr int MOD = 1e9 + 7;

int DP[MAXN];

int dice(int n, int accum = 0) {
	if (DP[accum])  return DP[accum];
	if (accum > n)  return 0;
	if (accum == n) return 1;

	int ways = 0;
	for (int i = 6; i > 0; i--)
		ways = (ways + dice(n, accum + i)) % MOD;

	return DP[accum] = ways;
}

int main() {
	int N;
	cin >> N;
	cout << dice(N) << flush;
}
