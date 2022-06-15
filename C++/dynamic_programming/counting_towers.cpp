#include <iostream>
#include <vector>
#include <string>

using namespace std;

constexpr int MAXN = 1e6;
constexpr int MOD = 1e9 + 7;

enum State {
	BothClosed,
	BigClosed,
	LeftOpen,
	RightOpen,
	BothOpen,
	BigOpen,
	Size,
};

// we regard 0th pos as beyond end position
int DP[MAXN + 1][State::Size];

const vector<State> transitions[State::Size] = {
	// both closed
	{BothClosed, BigClosed, LeftOpen, RightOpen, BothOpen, BigOpen},
	// big closed
	{BothClosed, BigClosed, LeftOpen, RightOpen, BothOpen, BigOpen},
	// left open
	{BothClosed, LeftOpen, RightOpen, BothOpen},
	// right open
	{BothClosed, LeftOpen, RightOpen, BothOpen},
	// both open
	{BothClosed, LeftOpen, RightOpen, BothOpen},
	// big open
	{BigClosed, BigOpen},
};

int count_towers(int n, State prev = State::BothClosed) {
	if (!n)
		return prev == State::BothClosed || prev == State::BigClosed;

	if (DP[n][prev])
		return DP[n][prev];

	int sum = 0;
	for (State set_this_state : transitions[prev]) {
		sum += count_towers(n - 1, set_this_state);
		if (sum >= MOD)
			sum -= MOD;
	}

	return DP[n][prev] = sum;
}

int main() {
	int t, N;
	cin >> t;
	for (int i = t; i--;) {
		cin >> N;
		cout << count_towers(N) << endl;
	}	
}
