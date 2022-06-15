#include <iostream>
#include <vector>
#include <string>

using namespace std;

constexpr int N = 8;
constexpr char FREE = '.';
constexpr char OCCUPIED = '*';

char BOARD[N][N];
int queen_row[N];

bool is_blocked(int column, int row) {
	if (BOARD[column][row] == OCCUPIED)
		return true;

	for (int col = 0; col < column; ++col) {
		// empty
		if (queen_row[col] == -1)
			continue;

		// same row
		if (queen_row[col] == row)
			return true;

		// same diagonal
		if (abs(queen_row[col] - row) == abs(col - column))
			return true;
	}

	return false;
}

int queens(int column = 0) {
	if (column == N)
		return 1;

	int sum = 0;
	for (int row = 0; row < N; ++row) {
		if (is_blocked(column, row))
			continue;

		queen_row[column] = row;
		sum += queens(column + 1);
		queen_row[column] = -1;
	}
	return sum;
}

int main() {
	for (int i = N; i--;)
		queen_row[i] = -1;

	for (int i = 0; i < N; ++i)
		for (int j = 0; char c = getchar(); ++j) {
			if (c == '\n') break;
			BOARD[j][i] = c;
		}

	cout << queens() << flush;
}
