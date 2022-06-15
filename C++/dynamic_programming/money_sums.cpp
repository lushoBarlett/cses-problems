#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

set<size_t> money_sums(vector<size_t>& coins) {
	sort(coins.begin(), coins.end());
	set<size_t> sums = {coins[0]};
	for (auto it = next(coins.begin()); it != coins.end(); it++) {
		unordered_set<size_t> temp = {*it};
		for (size_t s : sums)
			temp.insert(s + *it);
		sums.insert(temp.begin(), temp.end());
	}
	return sums;
}

int main() {
	size_t N, a;
	cin >> N;
	vector<size_t> v;
	for (size_t i = 0; i < N; i++) {
		cin >> a;
		v.push_back(a);
	}
	
	set<size_t> sums = money_sums(v);
	cout << sums.size() << endl;
	for (size_t s : sums)
		cout << s << ' ';
	cout << endl;
}