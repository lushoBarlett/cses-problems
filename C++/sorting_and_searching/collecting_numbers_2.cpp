#include <iostream>
#include <vector>
#include <string>

using namespace std;

constexpr uint MAXN = 2e5;

void rounds(vector<uint>& numbers, uint swaps) {
	uint positions[MAXN];
	uint index = 0;
	for (auto n : numbers)
		positions[n - 1] = index++;

	uint result = 1;
	for(uint i = 1; i < numbers.size(); i++)
		result += positions[i] < positions[i - 1];

	int a, b;
	for (uint i = 0; i < swaps; i++) {
		cin >> a >> b;
		a--;
		b--;
		if (b < a)
			std::swap(a, b);

		if (a == b) {
			cout << result << endl;
			continue;
		}

		std::swap(numbers[a], numbers[b]);
		int n_b = numbers[a] - 1;
		int n_a = numbers[b] - 1;

		int before_a = n_a - 1 < 0 ? -1 : positions[n_a - 1];
		int before_b = n_b - 1 < 0 ? -1 : positions[n_b - 1];
		int after_a  = n_a + 1 >= numbers.size() ? -1 : positions[n_a + 1];
		int after_b  = n_b + 1 >= numbers.size() ? -1 : positions[n_b + 1];

		std::swap(positions[n_a], positions[n_b]);

		if (a < before_a && before_a <= b)
			result--;
		
		if (a < after_a && after_a <= b)
			result++;

		if (a < before_b && before_b < b)
			result++;
		
		if (a < after_b && after_b < b)
			result--;

		cout << result << endl;
	}
}

int main() {
	uint N, M;
	vector<uint> v;
	cin >> N >> M;
	for (uint i = N; i--;) {
		uint a;
		cin >> a;
		v.push_back(a);
	}

	rounds(v, M);
}
