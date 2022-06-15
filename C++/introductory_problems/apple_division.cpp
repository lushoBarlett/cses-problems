#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define repeat(n) for (int _it = n; _it--;)

using namespace std;

constexpr int MAXN = 20;
vector<int> apples;

long long divide_equally(int pos = 0, long long a = 0, long long b = 0) {
	for (int i = pos; i < apples.size(); ++i) {
		return min(
			divide_equally(pos + 1, a + apples[pos], b), // chose set a
			divide_equally(pos + 1, a, b + apples[pos])  // chose set b
		);
	}
	return abs(b - a);
}

int main() {
	int N;
	cin >> N;
	repeat(N) {
		int a;
		cin >> a;
		apples.push_back(a);
	}

	cout << divide_equally() << flush;
}
