#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;
	if (N == 1) {
		cout << 1 << flush;
		return 0;
	}
	if (N < 4) {
		cout << "NO SOLUTION" << flush;
		return 0;
	}
	
	for (int inc = 2; inc <= N; inc += 2)
		cout << inc << ' ';

	for (int inc = 1; inc <= N; inc += 2)
		cout << inc << ' ';

	cout << flush;
}
