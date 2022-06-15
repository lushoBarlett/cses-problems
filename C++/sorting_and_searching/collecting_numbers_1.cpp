#include <iostream>
#include <vector>
#include <string>

using namespace std;

constexpr uint MAXN = 2e5;

uint rounds(vector<uint>& numbers) {
	uint positions[MAXN];
	uint index = 0;
	for (auto n : numbers)
		positions[n - 1] = index++;

	uint result = 1;
	for(uint i = 1; i < numbers.size(); i++)
		result += positions[i] < positions[i - 1];
	return result;
}

int main() {
	uint N;
	vector<uint> v;
	cin >> N;
	for (uint i = N; i--;) {
		uint a;
		cin >> a;
		v.push_back(a);
	}

	cout << rounds(v) << endl;
}
