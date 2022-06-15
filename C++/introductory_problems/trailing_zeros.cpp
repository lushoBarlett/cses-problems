#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

// NOTE: there are as many zeroes as 5s
// appear as prime factors of any of the
// numbers in the factorial multiplication
// (2s are abundant, so they don't matter)

constexpr int NUMBER = 5;

int multiples_up_to(int n) {
	return int(n / NUMBER);
}

int maximum_power_fitting(int n) {
	int times = 0;
	for (int i = NUMBER; i <= n; i *= NUMBER)
		++times;
	return times;
}

int maximum_multiple_fitting(int a, int b) {
	return int(a / b);
}

int main() {
	int N;
	cin >> N;

	int zeros = 0;
	// `i` represents the number of 5s of the number in question (5^i)
	// every multiple of that number also has that many 5s. But this is true
	// if we exclude multiplying by 5 or 10 or 15, that's why we substract
	// the appearances of these numbers of the multiples of 5^i up to
	// the maximum that fits N.
	for (int i = maximum_power_fitting(N); i > 0; i--) {
		int power = pow(NUMBER, i);
		int fitting = maximum_multiple_fitting(N, power);
		zeros += (fitting - multiples_up_to(fitting)) * i;
	}

	cout << zeros << flush;
}
