#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	unsigned long long n;
	cin >> n;

	cout << n << ' ';
	while (n != 1)
		cout << (n = (n % 2) ? (n * 3 + 1) : (n / 2)) << ' ';
	cout << flush;
}
