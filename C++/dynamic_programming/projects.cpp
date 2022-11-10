#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

constexpr int MAXN = 2e5;

const int Take = 0;
const int NotTake = 1;

struct Project {
	int beg;
	int end;
	int pay;

	bool operator<(const Project b) const {
		return beg < b.beg || (beg == b.beg && end < b.end);
	}
};

long long DP[MAXN][2];

long long maximum_pay(vector<Project>& projects, int project = 0) {
	if (project >= projects.size())
		return 0;

	if (DP[project][Take] == 0) {
		DP[project][NotTake] = maximum_pay(projects, project + 1);
		
		Project p = projects[project];
		Project search = { p.end + 1, p.end + 1 };
		
		auto next_takeable = lower_bound(projects.begin(), projects.end(), search);

		int next_takeable_index = distance(projects.begin(), next_takeable);

		DP[project][Take] = maximum_pay(projects, next_takeable_index) + p.pay;
	}

	return max(DP[project][Take], DP[project][NotTake]);
}

int main() {
	int N;
	cin >> N;
	vector<Project> projects;
	projects.resize(N);
	for (int i = 0; i < N; i++)
		cin >> projects[i].beg >> projects[i].end >> projects[i].pay;

	sort(projects.begin(), projects.end());
	cout << maximum_pay(projects) << endl;
}
