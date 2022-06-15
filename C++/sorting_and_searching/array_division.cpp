#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;
using big = long long;

// assumes no single element is bigger than max
bool with_max_sum(vector<int>& n, int k, big max) {
	int subs = 1;
	big current_sum = 0;
	for(auto a : n) {
		if (current_sum + a > max) {
			subs++;
			current_sum = 0;
		}
		current_sum += a;
	}

	return subs <= k;
}

big min_max_range(vector<int>& n, int k) {
	big lo = 0, hi = accumulate(n.begin(), n.end(), big(0));
	int max_elem = *max_element(n.begin(), n.end());

	while(lo + 1 < hi) {
		big m = (lo + hi) / 2;
		if (max_elem <= m and with_max_sum(n, k, m))
			hi = m;
		else
			lo = m;
	}

	return hi;
}

int main() {
	int N, K, a;
	cin >> N >> K;
	vector<int> n;
	for(int i = N; i--;) {
		cin >> a;
		n.push_back(a);
	}
	cout << min_max_range(n, K) << flush;
}
