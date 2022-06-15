#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

struct TempOrder {
	int index;
	int value;

	// first by value then by index (backwards, to use upper_bound)
	constexpr bool operator<(const TempOrder& b) const {
		return value < b.value or
		    (value == b.value and index > b.index);
	}
};

int max_unique_songs(vector<TempOrder>& songs) {
	vector<TempOrder> ordered = songs;
	sort(ordered.begin(), ordered.end());

	// max subarray sum O(N) method, times the logN lookup
	int max_range = 1, max_ending_here = 0;
	for (int i = 0; i < songs.size(); ++i) {
		auto last_time = upper_bound(ordered.begin(), ordered.end(), songs[i]);
		
		// there was no last time, safe to add this song to current max
		if (last_time == ordered.end() or last_time->value != songs[i].value)
			max_ending_here++;
		// last time was before starting to count current max, also safe
		else if (max_ending_here < songs[i].index - last_time->index)
			max_ending_here++;
		// else, we know that the previous maximum is greater or equal than the
		// distance to the last song, so its safe to just use that distance.
		// There's a guarantee that no other songs are repeated in that range
		else
			max_ending_here = songs[i].index - last_time->index;

		max_range = max(max_range, max_ending_here);
	}

	return max_range;
}

int main() {
	int N, a;
	cin >> N;
	vector<TempOrder> n;
	for(int i = 0; i < N; ++i) {
		cin >> a;
		n.push_back({i, a});
	}

	cout << max_unique_songs(n) << flush;
}
