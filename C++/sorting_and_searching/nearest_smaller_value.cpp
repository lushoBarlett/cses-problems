#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

struct TOrder {
	int i;
	int v;

	bool operator<(const TOrder& b) const {
		return v < b.v or (v == b.v and i > b.i);
	}
};

void nearest(vector<TOrder>& values, vector<int>& answer) {
	auto inverse_index = [](TOrder a, TOrder b) -> bool {
		return a.i > b.i;
	};
	sort(values.begin(), values.end());
	// inverse index ordering
	set<TOrder, decltype(inverse_index)> next_lower(inverse_index);
	answer.resize(values.size());

	// insertion from lower to greater
	// with inverse index for clean end() comparison
	for(auto& v : values) {
		auto l = next_lower.upper_bound(v);
		if (l == next_lower.end())
			answer[v.i] = -1;
		else
			answer[v.i] = l->i;
		next_lower.insert(v);
	}
}

int main() {
	int N, a;
	cin >> N;
	vector<TOrder> n;
	vector<int> answer;
	for(int i = 0; i < N; i++) {
		cin >> a;
		n.push_back({i, a});
	}
	nearest(n, answer);
	for(const auto a : answer)
		cout << a+1 << ' ';
	cout << flush;
}
