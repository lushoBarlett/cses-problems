#include <bits/stdc++.h>

using namespace std;

bool generate(int n, int a, int b, vector<pair<int, int>>& plays) {
	if (n != a + b || a == 0 && b != 0 || b == 0 && a != 0)
		return false;

	for (int p = n; p > 0; p--) {
		auto other = ((p + a - 1) % n) + 1;
		plays.push_back({p, other});
	}

	return true;
}

int main() {
	int T;
	cin >> T;
	for (int i = T; i--;) {
		int n, a, b;
		cin >> n >> a >> b;
		auto ties = n - a - b;
		vector<pair<int, int>> plays;
		if (ties >= 0 && generate(n - ties, a, b, plays)) {
			cout << "YES" << endl;

			for (auto [x, y] : plays)
				cout << x << " ";
			for (int t = n - ties + 1; t <= n; t++)
				cout << t << " ";
			cout << endl;

			for (auto [x, y] : plays)
				cout << y << " ";
			for (int t = n - ties + 1; t <= n; t++)
				cout << t << " ";
			cout << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}