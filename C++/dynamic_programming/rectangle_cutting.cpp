#include <iostream>
#include <vector>
#include <string>

using namespace std;

constexpr size_t MAXN = 500 + 1;

size_t DP[MAXN][MAXN];

size_t min_cuts(size_t a, size_t b) {
	if (a == b)
		return 0;
	
	if (a < b)
		swap(a, b);

	if (DP[a][b])
		return DP[a][b];
	
	size_t mc = 1e9;

	// slow?
	for (size_t k = 1; k < a; k++)
		mc = min(mc, 1 + min_cuts(k, b) + min_cuts(a - k, b));
	for (size_t k = 1; k < b; k++)
		mc = min(mc, 1 + min_cuts(a, k) + min_cuts(a, b - k));

	return DP[a][b] = mc;
}

int main() {
	size_t a, b;
	cin >> a >> b;
	cout << min_cuts(a, b) << endl;
}