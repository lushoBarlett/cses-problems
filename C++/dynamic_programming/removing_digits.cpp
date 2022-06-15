#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

constexpr int MAXN = 1e6 + 1;

int DP[MAXN];

void min_steps(int n) {
	fill_n(DP + 1, MAXN - 1, MAXN);
	for(int i = 1; i <= n; ++i)
		for(int j = i; j; j /= 10)
			if (int d = j % 10) // non-zero
				DP[i] = min(DP[i], DP[i - d] + 1);
}

int main() {
	int N;
	cin >> N;
	min_steps(N);
	cout << DP[N] << endl;
}
