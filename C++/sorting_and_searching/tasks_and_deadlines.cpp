#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using big = long long;

struct Task {
	int duration;
	int deadline;

	big reward(big now) {
		return deadline - now;
	}

	bool operator<(const Task& b) {
		return
			duration < b.duration or
			(duration == b.duration and deadline < b.deadline);
	}
};

big max_reward(vector<Task>& tasks) {
	sort(tasks.begin(), tasks.end());
	big sum = 0, now = 0;
	for (auto& t : tasks) {
		now += t.duration;
		sum += t.reward(now);
	}
	return sum;
}

int main() {
	int N, a, b;
	cin >> N;
	vector<Task> n;
	for(int i = N; i--;) {
		cin >> a >> b;
		n.push_back({a, b});
	}
	cout << max_reward(n) << flush;
}
