#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int min_towers(vector<int>& cubes) {
	map<int,int> towers;
	
	for(const auto c : cubes) {
		auto tower_placement = towers.upper_bound(c);

		if (tower_placement != towers.end()) {
			if (tower_placement->second == 1)
				towers.erase(tower_placement);
			else
				tower_placement->second--;
		}

		if (towers.find(c) != towers.end())
			towers[c]++;
		else
			towers.insert({c, 1});
	}

	int sum = 0;
	for (const auto t : towers)
		sum += t.second;

	return sum;
}

int main() {
	int N, a;
	cin >> N;
	vector<int> n;
	for (int i = N; i--;) {
		cin >> a;
		n.push_back(a);
	}

	cout << min_towers(n) << flush;
}
