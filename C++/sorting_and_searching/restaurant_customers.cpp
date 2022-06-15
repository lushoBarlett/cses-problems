#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

constexpr bool Enter = true;
constexpr bool Leave = false;

struct Action {
	int time;
	bool action;
};

int max_clients(vector<Action>& actions) {
	sort(actions.begin(), actions.end(),
		[](const Action& a, const Action& b) -> bool {
			return a.time < b.time;
		}
	);

	int max_clients = 0, current_clients = 0;
	for (const auto& a : actions) {
		if (a.action == Enter)
			current_clients++;
		else
			current_clients--;

		max_clients = max(max_clients, current_clients);
	}

	return max_clients;
}

int main() {
	int N, a, b;
	cin >> N;
	vector<Action> n;
	for (int i = N; i--;) {
		cin >> a >> b;
		n.push_back({a, Enter});
		n.push_back({b, Leave});
	}

	cout << max_clients(n) << flush;
}
