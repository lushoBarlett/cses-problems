#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;

	int in;
	cin >> in;

	unsigned long long increases = 0;
	int max = in;
	for (int i = N - 1; i--;) {
		cin >> in;
		if (max > in)
			increases += max - in;
		else
			max = in;
	}
		
	cout << increases << flush;
}
