#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cassert>

using namespace std;

struct Range {
	int beg;
	int end;
	int index;
	bool contains = false;
	bool contained = false;
};

void range_check(vector<Range>& ranges) {
	auto beg_comp = [](Range a, Range b) {
		return a.beg < b.beg || (a.beg == b.beg && a.end > b.end);
	};

	auto end_comp = [](Range a, Range b) {
		return a.end < b.end || (a.end == b.end && a.beg > b.beg);
	};

	set<Range, decltype(beg_comp)> by_beg(beg_comp);
	set<Range, decltype(end_comp)> by_end(end_comp);

	by_beg.insert(ranges.begin(), ranges.end());
	by_end.insert(ranges.begin(), ranges.end());

	int biggest_begin = 0;
	while(by_beg.size()) {
		auto batch_delimeter = by_beg.begin();

		set<Range>::iterator inside;
		// contains erased elements case
		ranges[batch_delimeter->index].contains = biggest_begin >= batch_delimeter->beg;
		for (inside = by_end.begin(); inside->index != batch_delimeter->index; inside++) {
			ranges[batch_delimeter->index].contains = true;
			ranges[inside->index].contained = true;
			ranges[inside->index].contains = biggest_begin >= inside->beg;

			biggest_begin = max(biggest_begin, inside->beg);

			by_beg.erase(*inside);
		}

		biggest_begin = max(biggest_begin, batch_delimeter->beg);
		
		by_beg.erase(batch_delimeter);
		by_end.erase(by_end.begin(), inside);
		by_end.erase(*batch_delimeter);
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

	range_check(ranges);
	
	for (auto r : ranges)
		cout << r.contains << ' ';
	cout << endl;
	for (auto r : ranges)
		cout << r.contained << ' ';
	cout << endl;
}
