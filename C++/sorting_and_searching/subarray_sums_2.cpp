#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
using big = long long;

void insert(map<big, big>& m, big v) {
	if (m.find(v) != m.end())
		m[v]++;
	else
		m.insert({v, 1});
}

big subarrays2(vector<big>& n, big x) {
	big answer = 0, current_sum = 0;
	// there's always one integral (from 0 to 0) that is 0
	map<big, big> integrals;
	insert(integrals, 0);
	for(auto a : n) {
		current_sum += a;
		big want = current_sum - x;
		auto l = integrals.find(want);
		if (l != integrals.end())
			answer += l->second;
		insert(integrals, current_sum);
	}
	return answer;
}

int main() {
	big N, X, a;
	cin >> N >> X;
	vector<big> n;
	for(int i = N; i--;) {
		cin >> a;
		n.push_back(a);
	}
	cout << subarrays2(n, X) << flush;
}
