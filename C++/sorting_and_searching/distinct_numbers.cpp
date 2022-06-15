#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int N, a;
	vector<int> n;
	cin >> N;

	for (int i = N; i--;) {
		cin >> a;
		n.push_back(a);
	}

	sort(n.begin(), n.end());

	int unique = 1;
	for(int i = 1; i < N; ++i)
		if (n[i] != n[i - 1])
			unique++;

	cout << unique << flush;
}
