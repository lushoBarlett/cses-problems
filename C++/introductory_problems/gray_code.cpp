#include <iostream>
#include <vector>
#include <string>

using namespace std;

char flip(char c) {
	return c == '1' ? '0' : '1';
}

void gray_code(string& s, size_t beg = 0) {
	if (beg == s.size()) {
		cout << s << endl;
		return;
	}

	gray_code(s, beg + 1);
	s[beg] = flip(s[beg]);
	gray_code(s, beg + 1);
}

int main() {
	size_t input;
	cin >> input;
	string bits = string(input, '0');
	gray_code(bits);
}
