#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string dna;
	cin >> dna;

	int rep = 1;
	int max = 1;
	for(int i = 1; i < dna.size(); ++i) {
		if (dna[i] == dna[i - 1]) {
			rep++;
			max = rep > max ? rep : max;
		}
		else {
			rep = 1;
		}
	}

	cout << max << flush;
}
