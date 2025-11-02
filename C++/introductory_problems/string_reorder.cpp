#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1000000;

struct Occurrence {
	int n;
	char c;

	const bool operator<(Occurrence other) const {
		return n < other.n || (n == other.n && c < other.c);
	}
};

int main() {
	string s;
	cin >> s;

	map<char, int> chars;
	for (char c : s) {
		if (chars.find(c) == chars.end())
			chars[c] = 1;
		else
			chars[c]++;
	}

	set<Occurrence> occurrences;
	for (auto [c, n] : chars)
		occurrences.insert({ n, c });

	char last_printed_char = 0;
	for (size_t i = 0; i < s.size(); i++) {
		auto least = chars.begin();
		auto densest = occurrences.rbegin();
		if (/* hay algun caracter que tengo que poner ahora porque sino no entra */) {
			cout <<
			/* actualizo la estructura que traquea eso */
		}
		if (last_printed_char != (*least).first) {
			cout << (*least).first;
			last_printed_char = (*least).first;
			(*least).second--;
			if ((*least).second == 0)
				chars.erase(least);
		} else {
			auto next_least = next(least);
			if (next_least == chars.end()) {
				cout << -1;
				break;
			}
			cout << (*next_least).first;
			last_printed_char = (*next_least).first;
			(*next_least).second--;
			if ((*next_least).second == 0)
				chars.erase(next_least);
		}
	}
	cout << endl;
}