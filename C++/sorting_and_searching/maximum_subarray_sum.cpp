#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long max_subarray(vector<int>& numbers) {
	long long sum = 0, max_n = numbers[0];
	for(int i = 0; i < numbers.size(); ++i) {
		// sum represents the maximum subarray ending here
		sum = max((long long)numbers[i], sum + (long long)numbers[i]);
		// the maximum of those is the actual maximum
		max_n = max(max_n, sum);
	}
	return max_n;
}

int main() {
	int N, a;
	cin >> N;
	vector<int> n;
	for(int i = N; i--;) {
		cin >> a;
		n.push_back(a);
	}

	cout << max_subarray(n) << flush;
}
