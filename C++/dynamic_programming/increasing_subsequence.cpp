#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

constexpr int MAXN = 2e5;

const int Take = 0;
const int NotTake = 1;

struct subseq {
	int size;
	int first;

	bool operator<(const subseq b) const {
		return size < b.size || (size == b.size && first < b.first);
	}
};

int DP[MAXN][2];

int max_action(int row[2]) {
	return max(row[Take], row[NotTake]);
}

int max_next(set<subseq>& subsequences, int number) {
	int L = 0, R = MAXN + 1;

	while (R - L > 1) {
		int ms = (L + R) / 2;

		auto minmax = subsequences.upper_bound({ ms, number });

		if (minmax == subsequences.end() || number >= minmax->first)
			R = ms;
		else
			L = ms;
	}

	return L;
}

int longest_inc_sub(vector<int>& numbers) {
	
	const int n = numbers.size();

	set<subseq> subsequences;
	
	DP[n - 1][NotTake] = 0;
	DP[n - 1][Take] = 1;

	subsequences.insert({ 1, numbers[n - 1] });

	for (int i = n - 2; i >= 0; i--) {
		DP[i][NotTake] = max_action(DP[i + 1]);
		DP[i][Take] = 1 + max_next(subsequences, numbers[i]);

		subsequences.insert({ DP[i][Take], numbers[i] });
	}

	return max_action(DP[0]);
}

int main() {
	int N;
	cin >> N;
	vector<int> numbers;
	numbers.resize(N);
	for (int i = 0; i < N; i++)
		cin >> numbers[i];

	cout << longest_inc_sub(numbers) << endl;
}
