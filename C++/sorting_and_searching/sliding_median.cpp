#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

struct TOrder {
	int i;
	int v;

	bool operator<(const TOrder& b) const {
		return v < b.v or (v == b.v and i < b.i);
	}

	bool operator>(const TOrder& b) const {
		return v > b.v or (v == b.v and i > b.i);
	}

	bool operator<=(const TOrder& b) const {
		return v < b.v or (v == b.v and i <= b.i);
	}

	bool operator>=(const TOrder& b) const {
		return v > b.v or (v == b.v and i >= b.i);
	}
};

void sliding_median(vector<int>& n, int k, vector<int>& answer) {
	if (k == 1) {
		answer = n;
		return;
	}

	multiset<TOrder> window;
	multiset<TOrder>::iterator median;

	int main = 0;
	while(main < k) {
		window.insert({main, n[main]});
		main++;
	}
	
	{
		int current = 0;
		for(auto it = window.begin(); it != window.end(); it++, current++) {
			if (current == (k - 1) / 2) {
				median = it;
				answer.push_back(it->v);
				break;
			}
		}
	}

	while(main < n.size()) {
		TOrder insertion{main, n[main]};
		TOrder deletion{main - k, n[main - k]};

		window.insert(insertion);
		if (insertion < *median and window.size() % 2 == 0)
			median--;
		else if (insertion > *median and window.size() % 2 == 1)
			median++;

		if (deletion <= *median and window.size() % 2 == 0)
			median++;
		else if (deletion >= *median and window.size() % 2 == 1)
			median--;
		window.erase(deletion);

		answer.push_back(median->v);

		main++;
	}
}

int main() {
	int N, K, a;
	cin >> N >> K;
	vector<int> n, answer;
	for(int i = N; i--;) {
		cin >> a;
		n.push_back(a);
	}
	sliding_median(n, K, answer);
	
	for(auto a : answer)
		cout << a << ' ';
	cout << flush;
}
