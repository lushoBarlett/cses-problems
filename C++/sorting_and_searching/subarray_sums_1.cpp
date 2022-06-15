#include <iostream>
#include <vector>
#include <string>

using namespace std;

int subarrays(vector<int>& n, int x) {
	int answer = 0;
	int sum = n[0];
	for(int l = 0, r = 1; r <= n.size();) {
		if (sum == x)
			answer++;

		if (sum >= x)
			sum -= n[l++];
		else
			sum += n[r++];
	}
	return answer;
}

int main() {
	int N, X, a;
	cin >> N >> X;
	vector<int> n;
	for(int i = N; i--;) {
		cin >> a;
		n.push_back(a);
	}
	cout << subarrays(n, X) << flush;
}
