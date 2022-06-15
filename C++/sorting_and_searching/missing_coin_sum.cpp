#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

uint64_t min_missing(vector<uint>& coins) {
	sort(coins.begin(), coins.end());
	uint64_t max_reachable = 0;
	for (auto coin : coins) {
		if (coin > max_reachable + 1)
			return max_reachable + 1;
		max_reachable += coin;
	}
	return max_reachable + 1;
}

int main() {
	uint N, a;
	vector<uint> v;
	cin >> N;
	for (uint i = N; i--;) {
		cin >> a;
		v.push_back(a);
	}

	cout << min_missing(v) << endl;
}
