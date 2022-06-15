#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int gondolas(vector<int> weights, int max_weight) {
	sort(weights.begin(), weights.end());

	int sum = 0;
	for (auto a = weights.begin(), b = weights.end() - 1; a <= b;) {
		if (a == b) {
			a++;
		} else if (*a + *b <= max_weight) {
			a++; b--;
		} else if (*a < *b) {
			b--;
		} else {
			a++;
		}

		sum++;
	}

	return sum;
}

int main() {
	int N, X, a;
	cin >> N >> X;
	
	vector<int> n;
	
	for (int i = N; i--;) {
		cin >> a;
		n.push_back(a);
	}

	cout << gondolas(n, X) << flush;
}
