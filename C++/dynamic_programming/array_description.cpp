#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <numeric>

using namespace std;

constexpr int MAXM = 1e3;
constexpr int MOD = 1e9 + 7;

// [0, M + 1]
int DP[MAXM + 2];

struct SlidingSum {
	queue<int> m_container;
	int m_sum {0};

	void push(int i) {
		m_container.push(i);
		m_sum += i;
		if (m_sum >= MOD)
			m_sum -= MOD;
	}

	void pop() {
		m_sum -= m_container.front();
		m_container.pop();
		if (m_sum < 0)
			m_sum += MOD;
	}

	constexpr int sum() {
		return m_sum;
	}
};

void matches(vector<int>& array, int max_value) {
	// first element
	if (array[0] == 0)
		fill_n(DP + 1, max_value, 1);
	else
		DP[array[0]] = 1;

	for(int i = 1; i < array.size(); i++) {

		SlidingSum sliding_sum;

		sliding_sum.push(DP[0]);
		sliding_sum.push(DP[1]);

		for (int m = 1; m <= max_value; m++) {
			sliding_sum.push(DP[m + 1]);

			// either the options are not limited,
			// or they are, but we are here anyway
			DP[m] = array[i] == 0 or array[i] == m
				? sliding_sum.sum()
				: 0;

			sliding_sum.pop();
		}
	}
}

int main() {
	int N, M, a;
	cin >> N >> M;
	vector<int> n;
	for(int i = N; i--;) {
		cin >> a;
		n.push_back(a);
	}
	matches(n, M);
	int final_sum = 0;
	for (int i = 1; i <= M; i++) {
		final_sum += DP[i];
		if (final_sum >= MOD)
			final_sum -= MOD;
	}
	cout << final_sum << endl;
}
