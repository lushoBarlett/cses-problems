#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define forr(r, n) for (int i = r; i < n; i++)
#define forn(n) forr(0, n)

int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	forn(N) cin >> a[i];

	unordered_map<int, int> h;
	for (auto n : a)
		if (h.find(n) == h.end())
			h[n] = 1;
		else
			h[n]++;

	size_t result = 1;
	for (auto [k, v] : h) {
		// subsequences are constructed choosing one of the v options
		// for this unique value k, or by not choosing it at all.
		// this sums up to an independent choice of v + 1 values
		result *= v + 1;
		result %= MOD;
	}

	// subtract the empty subset
	cout << (result - 1 + MOD) % MOD << endl;
}