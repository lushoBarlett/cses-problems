#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

constexpr int N = 7;

bool V[N][N] = {false};
string IN;

struct Coord {
	int x, y;
	
	Coord(int _x, int _y) : x(_x), y(_y) {};

	Coord up()    { return Coord{x, y - 1}; }
	Coord down()  { return Coord{x, y + 1}; }
	Coord left()  { return Coord{x - 1, y}; }
	Coord right() { return Coord{x + 1, y}; }

	// out of bounds is occupied
	bool occupied() {
		return x < 0 or y < 0 or x >= N or y >= N or V[x][y];
	}

	bool operator==(const Coord& b) const {
		return x == b.x and y == b.y;
	}

	void mark()   { V[x][y] = true;  }
	void unmark() { V[x][y] = false; }
};

const Coord END{0, N - 1};

bool invalid(Coord here, char move) {
	// first case is out of bounds or occupied
	// second is a forced turn, if both sides are empty
	// one gets closed off and this is invalid
	switch(move) {
	case 'U':
		here = here.up();
		if (here.occupied())
			return true;
		if (here.up().occupied())
			return !here.left().occupied() and !here.right().occupied();
		break;
	case 'D':
		here = here.down();
		if (here.occupied())
			return true;
		if (here.down().occupied())
			return !here.left().occupied() and !here.right().occupied();
		break;
	case 'L':
		here = here.left();
		if (here.occupied())
			return true;
		if (here.left().occupied())
			return !here.up().occupied() and !here.down().occupied();
		break;
	case 'R':
		here = here.right();
		if (here.occupied())
			return true;
		if (here.right().occupied())
			return !here.up().occupied() and !here.down().occupied();
		break;
	}
	return false;
}

int valid_paths(Coord c, int option = 0) {
	// in the end goal ahead of time
	if (option < IN.size() and c == END)
		return 0;

	if (option == IN.size() and c == END)
		return 1;

	c.mark();
	int sum = 0;
	switch(IN[option]) {
	case 'U': sum  = invalid(c, 'U') ? 0 : valid_paths(c.up(),    option + 1); break;
	case 'D': sum  = invalid(c, 'D') ? 0 : valid_paths(c.down(),  option + 1); break;
	case 'L': sum  = invalid(c, 'L') ? 0 : valid_paths(c.left(),  option + 1); break;
	case 'R': sum  = invalid(c, 'R') ? 0 : valid_paths(c.right(), option + 1); break;
	default:
		  sum += invalid(c, 'U') ? 0 : valid_paths(c.up(),    option + 1);
		  sum += invalid(c, 'D') ? 0 : valid_paths(c.down(),  option + 1);
		  sum += invalid(c, 'L') ? 0 : valid_paths(c.left(),  option + 1);
		  sum += invalid(c, 'R') ? 0 : valid_paths(c.right(), option + 1);
	}

	c.unmark();
	return sum;
}

int main() {
	cin >> IN;
	cout << valid_paths(Coord{0,0}) << flush;
}
