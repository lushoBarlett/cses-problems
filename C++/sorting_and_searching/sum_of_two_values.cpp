#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

enum Comp { Exact, Small, Large, };
struct TempOrder {
	int original_pos;
	int value;

	constexpr bool operator<(const TempOrder& b) const {
		return value < b.value;
	}
};

Comp compare(int a, int b, int sum) {
	if (a + b < sum) return Comp::Small;
	if (a + b > sum) return Comp::Large;
	                 return Comp::Exact;
}

pair<int,int> exact_sum(vector<TempOrder>& nums, int sum) {
	sort(nums.begin(), nums.end());

	for(int i = 0, j = nums.size() - 1; i < j;) {
		switch(compare(nums[i].value, nums[j].value, sum)) {
		case Comp::Small: i++; break;
		case Comp::Large: j--; break;
		case Comp::Exact:
			return make_pair(nums[i].original_pos + 1, nums[j].original_pos + 1);
		}
	}

	return make_pair(-1, -1);
}

int main() {
	int N, X, a;
	cin >> N >> X;
	vector<TempOrder> n;
	for (int i = 0; i < N; ++i) {
		cin >> a;
		n.push_back({i, a});
	}

	pair<int,int> pos = exact_sum(n, X);

	if (pos.first == -1)
		cout << "IMPOSSIBLE";
	else
		cout << pos.first << ' ' << pos.second;
}
