#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using big = long long;

// NOTE: y grows "down" and x grows "right".
// each number in a layer is between
// the last layer's square (exclusive)
// and this layer's square (inclusive)
big spiral(int x, int y) {
	big layer = max(x,y);
	big last_square = (layer - 1) * (layer - 1);
	big this_square = layer * layer;

	// odd layer grows anti-clockwise
	if (layer % 2) 
		return y == layer ? last_square + x : this_square - y + 1;

	// even layer grows clockwise
	else
		return x == layer ? last_square + y : this_square - x + 1;
}

int main() {
	int T;
	cin >> T;
	for (int i = T; i--;) {
		int y, x;
		cin >> y >> x;
		cout << spiral(x, y) << endl;
	}
	cout << flush;
}
