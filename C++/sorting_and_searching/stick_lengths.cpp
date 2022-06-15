#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using big = long long;

big cost(vector<big>& ss, big x) {
	big sum = 0;
	for (const auto s : ss)
		sum += abs(s - x);
	return sum;
}

// function is first decreasing
// then increasing
big min_cost(vector<big>& sticks) {
	big low  = *min_element(sticks.begin(), sticks.end());
	big high = *max_element(sticks.begin(), sticks.end());

	while(low < high) {
		if (low + 1 == high)
			return min(cost(sticks, low), cost(sticks, high));

		big mid = (low + high) / 2;
		if (cost(sticks, mid) > cost(sticks, mid + 1))
			low = mid;
		else
			high = mid;
	}

	return cost(sticks, low);
}

int main() {
	int N, a;
	vector<big> n;
	cin >> N;
	for (int i = N; i--;) {
		cin >> a;
		n.push_back(a);
	}

	cout << min_cost(n) << flush;
}
