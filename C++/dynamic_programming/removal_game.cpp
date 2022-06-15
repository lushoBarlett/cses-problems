#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <numeric>

using namespace std;

constexpr int MAXN = 5000;

long long DP[MAXN][MAXN];

long long optimal_removal(list<int>& numbers, long long sum, size_t removed_first = 0, size_t removed_last = 0) {

	if (!numbers.size())
		return 0LL;

	auto& dp = DP[removed_first][removed_last];
	if (dp)
		return dp;

	const int removal_first = numbers.front(); numbers.pop_front();
	const auto first = optimal_removal(numbers, sum - removal_first, removed_first + 1, removed_last);
	numbers.push_front(removal_first);

	const int removal_last = numbers.back(); numbers.pop_back();
	const auto last = optimal_removal(numbers, sum - removal_last, removed_first, removed_last + 1);
	numbers.push_back(removal_last);

	return dp = max(sum - first, sum - last);
}

int main() {
	size_t N;
	int a;
	cin >> N;
	list<int> n;
	for (size_t i = 0; i < N; i++) {
		cin >> a;
		n.push_back(a);
	}
	cout << optimal_removal(n, accumulate(n.begin(), n.end(), 0LL)) << endl;
}