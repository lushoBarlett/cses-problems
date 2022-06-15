#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <numeric>
#include <algorithm>

using namespace std;
using big = long long;

struct TOrder {
	int i;
	int v;

	bool operator<(const TOrder& b) const {
		return v < b.v or (v == b.v and i < b.i);
	}

	bool operator>(const TOrder& b) const {
		return v > b.v or (v == b.v and i > b.i);
	}

	bool operator<=(const TOrder& b) const {
		return v < b.v or (v == b.v and i <= b.i);
	}

	bool operator>=(const TOrder& b) const {
		return v > b.v or (v == b.v and i >= b.i);
	}
};

void sliding_cost(vector<int>& n, int k, vector<big>& answer) {
	if (k == 1) {
		answer.resize(n.size());
		fill(answer.begin(), answer.end(), 0);
		return;
	}

	set<TOrder> window;
	set<TOrder>::iterator median;

	big cost;
	int main = 0;
	while(main < k) {
		window.insert({main, n[main]});
		main++;
	}
	
	{
		int current = 0;
		for(auto it = window.begin(); it != window.end(); it++, current++) {
			if (current == (k - 1) / 2) {
				median = it;
				break;
			}
		}

		cost = accumulate(window.begin(), window.end(), big(0),
		    [&median](big accum, const TOrder& n) { return accum + abs(n.v - median->v); });

		answer.push_back(cost);
	}


	while(main < n.size()) {
		TOrder insertion{main, n[main]};
		TOrder deletion{main - k, n[main - k]};

		window.insert(insertion);
		cost += abs(median->v - insertion.v);
		if (insertion < *median and window.size() % 2 == 0) {
			median--;
		} else if (insertion > *median and window.size() % 2 == 1) {
			median++;
			cost -= median->v - prev(median)->v;
		}

		if (deletion <= *median and window.size() % 2 == 0) {
			median++;
		} else if (deletion >= *median and window.size() % 2 == 1) {
			median--;
			cost += next(median)->v - median->v;
		}
		cost -= abs(median->v - deletion.v);
		window.erase(deletion);

		answer.push_back(cost);

		main++;
	}
}

int main() {
	int N, K, a;
	cin >> N >> K;
	vector<int> n;
	vector<big> answer;
	for(int i = N; i--;) {
		cin >> a;
		n.push_back(a);
	}
	sliding_cost(n, K, answer);
	
	for(auto a : answer)
		cout << a << ' ';
	cout << flush;
}
