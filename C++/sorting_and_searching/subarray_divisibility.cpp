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

big subarrayd(vector<big>& n, big x) {
	big answer = 0, current_sum = 0;
	// there's always one integral (from 0 to 0) that is 0 % x = 0
	map<big, big> mod_integrals;
	insert(mod_integrals, 0);
	for(auto a : n) {
		current_sum = (x + ((current_sum + a) % x)) % x;
		auto l = mod_integrals.find(current_sum);
		if (l != mod_integrals.end())
			answer += l->second;
		insert(mod_integrals, current_sum);
	}
	return answer;
}

int main() {
	big N, a;
	cin >> N;
	vector<big> n;
	for(int i = N; i--;) {
		cin >> a;
		n.push_back(a);
	}
	cout << subarrayd(n, N) << flush;
}
