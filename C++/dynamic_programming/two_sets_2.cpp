#include <iostream>
#include <vector>
#include <string>

using namespace std;

constexpr int MAXN = 500;
constexpr int MAXSUM = (MAXN * MAXN + 1) / 2;
constexpr int MOD = 1e9 + 7;

int DP[MAXN][MAXSUM];

int partition_amount(int N, int maxsum, int number = 1, int sum = 0) {
	if (number == N)
		return sum == (maxsum / 2);
	
	auto& dp = DP[number - 1][sum];
	if (dp != -1)
		return dp;

	dp = partition_amount(N, maxsum, number + 1, sum + number) +
	     partition_amount(N, maxsum, number + 1, sum);

	if (dp >= MOD)
		dp -= MOD;

	return dp;
}

int main() {
	int N;
	cin >> N;

	for (size_t i = 0; i < MAXN; i++)
		for (size_t j = 0; j < MAXSUM; j++)
			DP[i][j] = -1;

	const int maxsum = N * (N + 1) / 2;
	cout << (maxsum % 2 ? 0 : partition_amount(N, maxsum)) << endl;
}