#include <iostream>
#include <vector>
#include <string>

using namespace std;
constexpr int MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;
	int power = 1;
	for (int i = N; i--; power = (2 * power) % MOD);
	cout << power << flush;
}
