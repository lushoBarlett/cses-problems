#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using big = long long;

struct TOrder {
	big index1;
	big index2;
	big value;

	bool operator<(const TOrder& b) const {
		return value < b.value;
	}
};

void answer(TOrder i, TOrder j) {
	cout << i.index1+1 << ' ' << i.index2+1 << ' ' << j.index1+1 << ' ' << j.index2+1 << flush;
}

bool index_check(TOrder i, TOrder j) {
	return
		i.index1 != j.index1 and
		i.index1 != j.index2 and
		i.index2 != j.index1 and
		i.index2 != j.index2;
}

void four_numbers(vector<TOrder>& n, big x) {
	sort(n.begin(), n.end());
	if (n.size() < 2) {
		cout << "IMPOSSIBLE" << flush;
		return;
	}
	for(big i = 0; i < n.size() and n[i].value < x; i++) {
		big lo = -1, hi = n.size() - 1;
		while(lo + 1 < hi) {
			big m = (lo + hi) / 2;
			if (n[i].value + n[m].value == x and i != m and index_check(n[i],n[m])) {
				answer(n[i],n[m]);
				return;
			}
			if (n[i].value + n[m].value >= x)
				hi = m;
			else
				lo = m;
		}
		if (n[i].value + n[hi].value == x and i != hi and index_check(n[i],n[hi])) {
			answer(n[i],n[hi]);
			return;
		}
	}
	cout << "IMPOSSIBLE" << flush;
}

int main() {
	big N, X, a;
	cin >> N >> X;
	vector<big> n;
	vector<TOrder> m;
	for(big i = 0; i < N; i++) {
		cin >> a;
		n.push_back(a);
	}

	for(big i = 0; i < N; i++) {
		for(big j = i + 1; j < N; j++) {
			m.push_back({i,j,n[i] + n[j]});
		}
	}

	four_numbers(m, X);
}
