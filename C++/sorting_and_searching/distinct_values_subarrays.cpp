#include <bits/stdc++.h>

using namespace std;

size_t subarray_count(size_t n) {
	return n * (n + 1) / 2;
}

struct Pos {
	size_t value;
	size_t pos;

	const bool operator==(Pos other) const {
		return value == other.value;
	}
};

template<>
struct std::hash<Pos> {
	std::size_t operator()(const Pos& pos) const {
		return std::hash<size_t>()(pos.value);
	}
};

size_t index_of(size_t n, unordered_set<Pos>& m) {
	auto pos = m.find({ n, 0 });
	assert(pos != m.end());
	return pos->pos;
}

// for each removal, count hoy many subarrays
// have that element as its first
size_t remove_all_up_to(size_t n, unordered_set<Pos>& m, size_t curr_index) {
	size_t count = 0;
	size_t index = index_of(n, m);
	for (auto pos = m.begin(); pos != m.end();) {
		if (pos->pos <= index) {
			assert(pos->pos < curr_index);
			count += curr_index - pos->pos;
			auto n = pos;
			pos++;
			m.erase(n);
		} else {
			pos++;
		}
	}
	return count;
}

int main() {
	size_t N;
	cin >> N;
	vector<size_t> array(N);
	for (size_t i = 0; i < N; i++)
		cin >> array[i];

	size_t count = 0;
	unordered_set<Pos> max_subarray;
	for (size_t i = 0; i < N; i++) {
		auto n = array[i];
		if (max_subarray.find({ n, 0 }) == max_subarray.end()) { // unique: increment the subarray
			max_subarray.insert({ n, i });
		} else { // repeated: count now, and remove the elements from the repeated to the left
			count += remove_all_up_to(n, max_subarray, i);
			max_subarray.insert({ n, i });
		}
	}
	count += subarray_count(max_subarray.size()); // last one simply counts all
	cout << count << endl;
}
