#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAXN = 2*1e5;

int main() {
	bool visited[MAXN];
	int N;
	cin >> N;

	for (int i = N - 1; i--;) {
		int a;
		cin >> a;
		visited[a - 1] = true;
	}

	int i = 0;
	while(visited[i++]);

	cout << i << flush;
}
