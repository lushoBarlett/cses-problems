#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1000000;

size_t chars[26];

pair<char, size_t> calculate_densest() {
	char c = 0;
	size_t max = 0;
	for (int i = 0; i < 26; i++)
		if (chars[i] > max) {
			c = i + 'A';
			max = chars[i];
		}
	return {c, max};
}

pair<char, char> calculate_two_smallest() {
	pair<char, char> cs = {0,0};
	for (int i = 0; i < 26; i++)
		if (chars[i] > 0 && !cs.first)
			cs.first = i + 'A';
		else if (chars[i] > 0 && !cs.second)
			cs.second = i + 'A';
	return cs;
}

int main() {
	string s;
	stringstream r;
	cin >> s;

	for (char c : s)
		chars[c - 'A']++;

	char last_printed_char = 0;
	for (size_t i = 0; i < s.size(); i++) {
		auto densest = calculate_densest();
		auto chars_left = s.size() - i;
		if (densest.second * 2 - 1 == chars_left) { // eg: A*A*A*A
			if (last_printed_char == densest.first) {
				cout << -1 << endl;
				exit(0);
			}
			r << densest.first;
			last_printed_char = densest.first;
			chars[densest.first - 'A']--;
			continue;
		}
		auto smallest = calculate_two_smallest();
		if (last_printed_char != smallest.first) {
			r << smallest.first;
			last_printed_char = smallest.first;
			chars[smallest.first - 'A']--;
		} else {
			if (smallest.second == 0) {
				cout << -1 << endl;
				exit(0);
			}
			r << smallest.second;
			last_printed_char = smallest.second;
			chars[smallest.second - 'A']--;
		}
	}
	cout << r.str() << endl;
}
