#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;
using big = long long;

big min_time(vector<big>& read_times) {
	sort(read_times.begin(), read_times.end());
	big sum = accumulate(read_times.begin(), read_times.end(), (big)0);
	return sum + max(big(0), big(2 * *read_times.rbegin()) - sum);
}

int main() {
	int N, a;
	cin >> N;
	vector<big> n;
	for (int i = N; i--;) {
		cin >> a;
		n.push_back(a);
	}

	cout << min_time(n) << flush;
}
