#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

constexpr int MAXN = 1e6 + 1;
constexpr int MOD = 1e9 + 7;

set<int,greater<int>> coins;

int DP[MAXN] = {0};

void combinations(int n) {
	DP[n] = 1;
	for(int accum = n - 1; accum >= 0; accum--) {
		int amount = 0;
		for (const auto c : coins)
			if (accum + c <= n)
				amount = (amount + DP[accum + c]) % MOD;
		DP[accum] = amount;
	}
}

int main() {
	int C, N, a;
	cin >> C >> N;
	for (int i = C; i--;) {
		cin >> a;
		coins.insert(a);
	}
	combinations(N);
	cout << DP[0] << flush;
}
