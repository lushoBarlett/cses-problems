#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int MAXN = 1e6 + 1;
constexpr int MOD = 1e9 + 7;

vector<int> coins;
// second dimension is the integral
// of the amount of solutions from smaller
// to bigger coins
int DP[MAXN] = {0};

void combinations(int n) {
	DP[0] = 1;
	for (const auto c : coins)
		for(int i = c; i <= n; i++)
			DP[i] = (DP[i] + DP[i - c]) % MOD;
}

int main() {
	int C, N, a;
	cin >> C >> N;
	for (int i = C; i--;) {
		cin >> a;
		coins.push_back(a);
	}
	combinations(N);
	cout << DP[N] << endl;
}
