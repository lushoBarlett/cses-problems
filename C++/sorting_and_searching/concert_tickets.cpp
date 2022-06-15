#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

void tickets(multiset<int, greater<int>>& tickets, vector<int>& max_prices) {
	for (auto p = max_prices.begin(); p < max_prices.end(); p++) {
		auto equal_or_after = tickets.lower_bound(*p);

		if (equal_or_after == tickets.end()) {
			cout << -1 << '\n';
		} else {
			cout << *equal_or_after << '\n';
			tickets.erase(equal_or_after);
		}
	}

	cout << flush;
}

int main() {
	int N, M, a;
	cin >> N >> M;

	// flip order, so lower_bound returns an equal element
	// or the one "after" (which is lesser)
	multiset<int, greater<int>> n;
	for (int i = N; i--;) {
		cin >> a;
		n.insert(a);
	}

	vector<int> m;
	for (int i = M; i--;) {
		cin >> a;
		m.push_back(a);
	}

	tickets(n, m);
}
