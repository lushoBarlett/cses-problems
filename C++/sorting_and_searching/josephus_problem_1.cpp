#include <iostream>
#include <vector>
#include <string>
#include <forward_list>

using namespace std;

int main() {
	uint N;
	cin >> N;
	forward_list<uint> children;

	for (uint i = N; i >= 1; i--)
		children.push_front(i);

	auto it = children.begin();
	bool erase = true;
	while (!children.empty()) {
		if (it == children.end())
			it = children.begin();
		if (next(it) == children.end())
			it = children.before_begin();

		if (erase) {
			cout << *next(it) << endl;
			it = children.erase_after(it);
			erase = false;
		} else {
			erase = true;
		}
	}
}
