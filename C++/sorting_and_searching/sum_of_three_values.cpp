#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct TOrder {
	int index;
	int value;

	bool operator<(const TOrder& b) const {
		return value < b.value;
	}
};

void answer(TOrder i, TOrder j, TOrder k) {
	cout << i.index+1 << ' ' << j.index+1 << ' ' << k.index+1 << flush;
}

void three_numbers(vector<TOrder>& n, int x) {
	sort(n.begin(), n.end());
	if (n.size() < 3) {
		cout << "IMPOSSIBLE" << flush;
		return;
	}
	for(int i = 0; i < n.size() and n[i].value < x; i++) {
		for(int j = i + 1; j < n.size() and n[i].value + n[j].value < x; j++) {
			int lo = -1, hi = n.size() - 1;
			while(lo + 1 < hi) {
				int m = (lo + hi) / 2;
				if (n[i].value + n[j].value + n[m].value == x and i != m and j != m) {
					answer(n[i],n[j],n[m]);
					return;
				}
				if (n[i].value + n[j].value + n[m].value >= x)
					hi = m;
				else
					lo = m;
			}
			if (n[i].value + n[j].value + n[hi].value == x and i != hi and j != hi) {
				answer(n[i],n[j],n[hi]);
				return;
			}
		}
	}
	cout << "IMPOSSIBLE" << flush;
}

int main() {
	int N, X, a;
	cin >> N >> X;
	vector<TOrder> n;
	for(int i = 0; i < N; i++) {
		cin >> a;
		n.push_back({i, a});
	}
	three_numbers(n, X);
}
