#include <iostream>
#include <vector>
#include <string>

using namespace std;

constexpr int MAXC = 1e5;

int DP[MAXC + 1];

struct Book {
	int price;
	int pages;
};

void max_pages(vector<Book>& books, int max_price) {
	for(int spent = 0; spent <= max_price - books[0].price; spent++)
		DP[spent] += books[0].pages;

	for(int b_it = 1; b_it < books.size(); b_it++)
		// safe to skip because you can't choose to buy anyway
		// going forwards to avoid overriding usable data
		for(int spent = 0; spent <= max_price - books[b_it].price; spent++)
			DP[spent] = max(
				DP[spent + books[b_it].price] + books[b_it].pages, // take
				DP[spent] // not take
			);
}

int main() {
	int N, X, a;
	cin >> N >> X;
	vector<Book> n;
	for(int i = N; i--;) {
		cin >> a;
		n.push_back({a});
	}
	for(int i = 0; i < N; i++) {
		cin >> a;
		n[i].pages = a;
	}
	max_pages(n, X);
	cout << DP[0] << endl;
}
