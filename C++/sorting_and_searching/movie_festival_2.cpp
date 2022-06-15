#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

struct Movie {
	int b;
	int e;

	bool operator<(const Movie& b) const {
		return e < b.e or (e == b.e and this->b < b.b);
	}
};

int max_movies(vector<Movie>& movies, int k) {

	auto by_inverse_end = [](const Movie& a, const Movie& b) {
		// a beggining of 0 is guaranteed to go before every other movie that
		// ends at the same time, this is a trick for lower bound
		return a.e > b.e or (a.e == b.e and a.b < b.b);
	};

	multiset<Movie, decltype(by_inverse_end)> watching(by_inverse_end);
	sort(movies.begin(), movies.end());

	int answer = 0;
	for(auto movie = movies.begin(); movie != movies.end(); movie++) {
		// free up the last person that can watch this movie
		auto free = watching.lower_bound({0, movie->b});
		if (free != watching.end())
			watching.erase(free);
		
		// someone can watch this movie
		if (watching.size() < k) {
			watching.insert(*movie);
			answer++;
		}
	}

	return answer;
}

int main() {
	int N, K, a, b;
	cin >> N >> K;
	vector<Movie> n;
	for (int i = N; i--;) {
		cin >> a >> b;
		n.push_back({a, b}); // index is for when already sorted
	}
	cout << max_movies(n, K);
}
