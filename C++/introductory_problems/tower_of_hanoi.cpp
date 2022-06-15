#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum Tower { Left = 1, Middle = 2, Right = 3 };

Tower remaining (Tower a, Tower b) {
	switch (a) {
	case Left:   return b == Middle ? Right : Middle;
	case Middle: return b == Left   ? Right : Left;
	case Right:  return b == Middle ? Left  : Middle;
	}

	// should never happen
	return Left;
}

void move(uint n, Tower from = Left, Tower to = Right) {
	if (n == 1) {
		cout << from << ' ' << to << endl;
		return;
	}

	Tower rem = remaining(from, to);

	move(n - 1, from, rem);
	cout << from << ' ' << to << endl;
	move(n - 1, rem, to);
}

int main() {
	uint min_tower_moves[16] = {1};
	for (size_t i = 1; i < 16; i++)
		min_tower_moves[i] = min_tower_moves[i - 1] * 2 + 1;

	uint n;
	cin >> n;
	cout << min_tower_moves[n - 1] << endl;

	move(n);
}
