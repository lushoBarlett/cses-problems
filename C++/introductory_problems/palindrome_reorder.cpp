#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
	unordered_map<char, unsigned int> count{};
	string input;

	cin >> input;

	for (auto c : input) {
		if (count.find(c) == count.end())
			count[c] = 1;
		else
			count[c]++;
	}

	pair<char, unsigned int> odd = make_pair(0, 0);
	for(const auto& p : count) {
		if (p.second % 2) {
			// second odd amount found
			if (odd.first != 0) {
				cout << "NO SOLUTION" << flush;
				return 0;
			}
			odd = p;
		}
	}

	count.erase(odd.first);
	stringstream first, last;

	for(const auto& p : count) {
		for (unsigned int i = p.second / 2; i--;) {
			first << p.first;
			last << p.first;
		}
	}

	cout << first.str();

	for (unsigned int i = odd.second; i--;)
		cout << odd.first;

	string _last = last.str();
	reverse(_last.begin(), _last.end());
	cout << _last;

	cout << flush;
}
