#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Movie {
	int beg;
	int end;

	constexpr bool operator<(const Movie& b) const {
		return beg < b.beg;
	}
};

constexpr int MAXN = 2*1e5;
constexpr int EMPTY = -1;

int DP[MAXN];

int max_movies(vector<Movie>& movies, int it = 0) {
	if (it >= movies.size())
		return 0;

	if (DP[it] != EMPTY)
		return DP[it];

	int not_watched = max_movies(movies, it + 1);

	auto new_movie = lower_bound(movies.begin(), movies.end(), movies[it],
		[](const Movie& element, const Movie& this_movie) -> bool {
			return element.beg < this_movie.end;
		}
	);

	int watched = 1 + max_movies(movies, distance(movies.begin(), new_movie));

	return DP[it] = max(watched, not_watched);
}

int main() {
	int N, a, b;
	cin >> N;
	vector<Movie> n;
	for (int i = N; i--;) {
		cin >> a >> b;
		n.push_back({a, b});
	}

	fill_n(DP, MAXN, EMPTY);
	sort(n.begin(), n.end());
	cout << max_movies(n) << flush;
}
