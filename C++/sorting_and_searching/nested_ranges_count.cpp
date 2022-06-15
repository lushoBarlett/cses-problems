#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cassert>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T, typename U>
using ordered_set = tree<T, null_type, U, rb_tree_tag, tree_order_statistics_node_update>;

struct Range {
	int beg;
	int end;
	int index;
	int contains = 0;
	int contained = 0;
};

void compute_contains(vector<Range>& ranges) {
	auto beg_comp = [](Range a, Range b) {
		return a.beg > b.beg || (a.beg == b.beg && a.end < b.end);
	};

	auto end_comp = [](Range a, Range b) {
		return a.end < b.end || (a.end == b.end && a.beg > b.beg);
	};

	ordered_set<Range, decltype(beg_comp)> by_beg(beg_comp);
	set<Range, decltype(end_comp)> by_end(end_comp);

	by_end.insert(ranges.begin(), ranges.end());
	for(auto r : by_end) {
		ranges[r.index].contains = by_beg.order_of_key(r);
		by_beg.insert(r);
	}
}

void compute_contained(vector<Range>& ranges) {
	auto beg_comp = [](Range a, Range b) {
		return a.beg < b.beg || (a.beg == b.beg && a.end > b.end);
	};

	auto end_comp = [](Range a, Range b) {
		return a.end > b.end || (a.end == b.end && a.beg < b.beg);
	};

	set<Range, decltype(beg_comp)> by_beg(beg_comp);
	ordered_set<Range, decltype(end_comp)> by_end(end_comp);

	by_beg.insert(ranges.begin(), ranges.end());
	for(auto r : by_beg) {
		ranges[r.index].contained = by_end.order_of_key(r);
		by_end.insert(r);
	}
}

int main() {
	int N, a, b;
	cin >> N;
	vector<Range> ranges;
	for (int i = N; i--;) {
		cin >> a >> b;
		ranges.push_back({a, b, int(ranges.size())});
	}

	compute_contains(ranges);
	compute_contained(ranges);
	
	for (auto r : ranges)
		cout << r.contains << ' ';
	cout << endl;
	for (auto r : ranges)
		cout << r.contained << ' ';
	cout << endl;
}
