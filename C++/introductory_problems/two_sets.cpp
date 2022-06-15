#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;

	if ((N * (N + 1)) % 4) {
		cout << "NO" << flush;
		return 0;
	}

	cout << "YES" << '\n';
	if (N % 2) {
		// smaller set first
		cout << N / 2 << '\n';
		cout << N << ' ';

		int it = 1;
		for (int i = (N + 1) / 4 - 1; i--; ++it)
			cout << it << ' ' << N - it << ' ';

		cout << '\n' << N / 2 + 1 << '\n';
		for (int i = (N + 1) / 4; i--; ++it)
			cout << it << ' ' << N - it << ' ';

		cout << flush;
		return 0;
	}

	int it = 1;
	cout << N / 2 << '\n';
	for (int i = N / 4; i--; ++it)
		cout << it << ' ' << N + 1 - it << ' ';

	cout << '\n' << N / 2 << '\n';
	for (int i = N / 4; i--; ++it)
		cout << it << ' ' << N + 1 - it << ' ';

	cout << flush;
}
