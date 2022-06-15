#include <iostream>
#include <vector>
#include <string>

using namespace std;
using big = unsigned long long;

// new layer horse can attack 2 - 4 places depending where it is
// x = edge       --> 2 | (2 times) = 4
// x = edge - 1   --> 3 | (2 times) = 6
// x = corner - 2 --> 3 | (2 times) = 6
// x = corner - 1 --> 2 | (2 times) = 4
// x = corner     --> 2 | (1 time ) = 2
// else           --> 4 | (every other time)
//
// NOTE: small layers have overlapping cases
// so we must calculate this by hand
// 5 is the first case in which (corner - 2) and (edge - 1) are different

constexpr big SUBS_ATTACK = 4 + 6 + 6 + 4 + 2;
constexpr big SUBS_SQUARES = 2 + 2 + 2 + 2 + 1;

big block_layer_attacks(big layer_squares) {
	if (layer_squares == 3) return 6;
	if (layer_squares == 4) return 14;

	return SUBS_ATTACK + (layer_squares - SUBS_SQUARES) * 4;
}

// NOTE: the order of the knights does not matter.
// a solution (p1, p2) is the same as (p2, p1)
void count_non_attack(vector<big>& answer, int n) {
	// special cases, hand calculated
	if (n == 1) {
		answer[n - 1] = 0;
		return;
	}

	if (n == 2) {
		answer[n - 1] = 6;
		return;
	}

	// both horses in a square one layer shorter
	// (already subtracted attack positions)
	count_non_attack(answer, n - 1);

	big layer_squares = 2 * n - 1;
	big last_block_squares = (n - 1) * (n - 1);

	// both horses in the new layer
	big layer_choose_2 = layer_squares * (layer_squares - 1) / 2;
	
	// one in prev block and one in new layer
	big block_layer_choose_2 = last_block_squares * layer_squares;
	
	answer[n - 1] = answer[n - 2];
	answer[n - 1] += layer_choose_2 - 2;
	answer[n - 1] += block_layer_choose_2 - block_layer_attacks(layer_squares);
}

int main() {
	int N;
	cin >> N;
	vector<big> answer;
	answer.resize(N);
	count_non_attack(answer, N);
	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << '\n';

	cout << flush;
}
