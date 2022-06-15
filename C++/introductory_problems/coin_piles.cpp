#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool emptiable(int a, int b) {
	if (a == 0 and b == 0)
		return true;
	
	if (a > b)
		return emptiable(b, a);

	// b can be equal to a in
	// `diff` amount of turns.
	// Each turn can add or subtract
	// one from their difference
	// But each turn they both get smaller
	int diff = b - a;

	// difference is too big, not reachable
	if (a < diff)
		return false;

	int piles_equal_in = a - diff;
	
	// (0, 0) is true, (1, 1) and (2, 2) are false
	// this applies also by adding 3
	// as this represents 2 turns in the past
	if (piles_equal_in % 3 == 0)
		return true;

	return false;
}

int main() {
	int T;
	cin >> T;

	for (int i = T; i--;) {
		int a, b;
		cin >> a >> b;
		cout << (emptiable(a, b) ? "YES\n" : "NO\n");
	}

	cout << flush;
}
