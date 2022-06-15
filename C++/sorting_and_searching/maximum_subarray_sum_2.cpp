#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <climits>

using namespace std;
using big = long long;

big max_subarray(vector<int>& n, int a, int b) {
	multiset<big> sliding_integrals;
	vector<big> integrals{0};

	for (int i = 0; i < a - 1; ++i)
		integrals.push_back(integrals.back() + n[i]);

	big answer = integrals.back() + n[a - 1];
	for (int i = a - 1; i < n.size(); ++i) {
		integrals.push_back(integrals.back() + n[i]);

		sliding_integrals.insert(integrals[i - a + 1]);

		if (i >= b) {
			// erase only one element
			auto it = sliding_integrals.lower_bound(integrals[i - b]);
			sliding_integrals.erase(it);
		}

		answer = max(answer, integrals.back() - *sliding_integrals.begin());
	}

	return answer;
}

int main() {
	int N, A, B, a;
	cin >> N >> A >> B;
	vector<int> n;
	for(int i = N; i--;) {
		cin >> a;
		n.push_back(a);
	}
	cout << max_subarray(n, A, B) << flush;
}
