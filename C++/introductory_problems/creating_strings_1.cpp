#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

constexpr int MAXN = 8;
string IN;

void create_strings(vector<string>& answer, string& s, unordered_map<char,int>& options) {
	if (s.size() == IN.size())
		answer.push_back(s);

	// each unique char
	for(auto& p : options) {
		if (!p.second)
			continue;

		p.second--;
		s.push_back(p.first);

		create_strings(answer, s, options);

		s.pop_back();
		p.second++;
	}
}

int main() {
	cin >> IN;

	unordered_map<char,int> options;
	for (char c : IN) {
		if (options.count(c))
			options[c]++;
		else
			options[c] = 1;
	}

	vector<string> answer;
	string s;
	create_strings(answer, s, options);

	sort(answer.begin(), answer.end());

	cout << answer.size() << '\n';
	for (auto& s : answer)
		cout << s << '\n';

	cout << flush;
}
