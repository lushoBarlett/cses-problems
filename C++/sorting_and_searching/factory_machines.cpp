#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

using namespace std;

using big = long long;

big produces(big product_delay, big time) {
	assert(product_delay);
	return time / product_delay;
}

big whole_production(vector<int>& m, big time) {
	big sum = 0;
	for (auto d : m)
		sum += produces(d, time);
	return sum;
}

big min_time(vector<int>& machine_delays, int products) {
	// low is always false
	big low = 0;
	// high is always true
	big high = (big)*min_element(machine_delays.begin(), machine_delays.end()) * (big)products;

	while(low + 1 < high) {
		big m = (low + high) / 2;
		if (whole_production(machine_delays, m) >= products)
			high = m;
		else
			low = m;
	}

	return high;
}

int main() {
	int N, K, a;
	cin >> N >> K;
	vector<int> n;
	for(int i = N; i--;) {
		cin >> a;
		n.push_back(a);
	}
	cout << min_time(n, K) << flush;
}
