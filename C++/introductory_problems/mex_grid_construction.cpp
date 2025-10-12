#include <bits/stdc++.h>

using namespace std;

constexpr uint16_t MAXN = 100;

set<uint16_t> ex_by_column[MAXN];

void construct_full_ex(set<uint16_t>& ex, int n) {
	for (int k = 0; k < 2 * n; k++)
		ex.insert(k);
}

uint16_t min_ex_from_two_exs(set<uint16_t>& ex1, set<uint16_t>& ex2) {
	auto it1 = ex1.begin();
	auto it2 = ex2.begin();

	while (it1 != ex1.end() && it2 != ex2.end()) {
		if (*it1 < *it2)
			it1++;
		else if (*it1 > *it2)
			it2++;
		else /* (*it1 == *it2) */
			return *it1;
	}

	return -1;
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		construct_full_ex(ex_by_column[i], N);

	for (int i = 0; i < N; i++) {
		set<uint16_t> ex_row;
		construct_full_ex(ex_row, N);

		for (int j = 0; j < N; j++) {
			auto mex = min_ex_from_two_exs(ex_row, ex_by_column[j]);
			ex_row.erase(mex);
			ex_by_column[j].erase(mex);
			cout << (int)mex << " ";
		}
		cout << endl;
	}
}