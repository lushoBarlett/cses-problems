#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

uint64_t subarrays(vector<int>& values, int k) {
	uint64_t count = 0;
	int left = 0;

	map<int, int> window;
	int total_amount = 0;
	for (auto v : values) {
		window[v]++;
		total_amount++;

		while (window.size() > k) {
			int erase = values[left++];
			window[erase]--;
			total_amount--;
			if (window[erase] == 0)
				window.erase(erase);
		}

		count += total_amount;
	}
	return count;
}

int main() {
	int N, K, a;
	cin >> N >> K;
	vector<int> v;
	for (int i = N; i--;) {
		cin >> a;
		v.push_back(a);
	}

	cout << subarrays(v, K) << endl;
}
