#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

void print_max(map<int,int>& l) {
	cout << l.crbegin()->first << ' ';
}

void map_insert(map<int,int>& r, int x) {
	if (r.find(x) == r.end())
		r.insert({x, 1});
	else
		r[x]++;
}

void map_erase(map<int,int>& r, int x) {
	auto it = r.find(x);
	if (it != r.end()) {
		if (it->second == 1)
			r.erase(it);
		else
			it->second--;
	}
}

void max_road(vector<int>& lights, int road_length) {
	// ghost lights, not reachable so there's no end() or begin() condition
	set<int> current_lights = {0, road_length};

	map<int,int> segment_sizes = { {road_length, 1} };

	for(const auto& new_light : lights) {
		auto next_light = current_lights.upper_bound(new_light);
		auto prev_light = prev(next_light);

		map_erase(segment_sizes, *next_light - *prev_light);

		map_insert(segment_sizes, *next_light - new_light);
		map_insert(segment_sizes, new_light - *prev_light);

		current_lights.insert(new_light);

		print_max(segment_sizes);
	}
}

int main() {
	int N, X, a;
	cin >> X >> N;
	vector<int> n;
	for (int i = N; i--;) {
		cin >> a;
		n.push_back(a);
	}
	max_road(n, X);
}
