#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

constexpr int MAXN = 1e6 + 1;

set<int,greater<int>> coins;

int DP[MAXN] = {0};

void min_coins(int n) {
	for(int accum = n - 1; accum >= 0; accum--) {
		int amount = MAXN + 1;
		for (const auto c : coins) {
			if (accum + c > n)
				continue;
			amount = min(amount, DP[accum + c] + 1);
		}
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
	min_coins(N);
	cout << (DP[0] > MAXN ? -1 : DP[0]) << flush;
}
