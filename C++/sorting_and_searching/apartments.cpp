#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

enum Cond {
	Fits,
	TooSmall,
	TooLarge,
};

Cond condition(int app, int room, int tolerance) {
	if (app < room - tolerance)
		return Cond::TooLarge;
	if (app > room + tolerance)
		return Cond::TooSmall;
	return Cond::Fits;
}

int pair_ups(vector<int>& apps, vector<int>& rooms, int tolerance) {

	sort(apps.begin(), apps.end());
	sort(rooms.begin(), rooms.end());

	int pairs = 0;
	for (int i = 0, j = 0; i < apps.size() and j < rooms.size();) {
		switch(condition(apps[i], rooms[j], tolerance)) {
		case Cond::Fits:     pairs++; i++; j++; break;
		case Cond::TooSmall:               j++; break;
		case Cond::TooLarge:          i++;      break;
		}
	}

	return pairs;
}

int main() {
	int N, M, K;
	vector<int> n;
	vector<int> m;
	cin >> N >> M >> K;

	int a;
	for (int i = N; i--;) {
		cin >> a;
		n.push_back(a);
	}

	for (int i = M; i--;) {
		cin >> a;
		m.push_back(a);
	}

	cout << pair_ups(n, m, K) << flush;
}
