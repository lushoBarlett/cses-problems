#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

uint64_t ndigit(uint64_t k, uint64_t number, uint64_t digits) {
	k = digits - k - 1;
	while(k--) number /= 10;
	return number % 10;
}

uint64_t digit_query(uint64_t k) {
	if (k < 10)
		return k;

	uint64_t digit_size = 1;
	uint64_t number_amount = 9;
	while(k > number_amount * digit_size) {
		k -= number_amount * digit_size;
		number_amount *= 10;
		digit_size += 1;
	}

	uint64_t number = number_amount/9 + (k - 1)/digit_size;
	return ndigit((k + digit_size - 1) % digit_size, number, digit_size);
}

int main() {
	uint64_t Q;
	uint64_t k;
	cin >> Q;
	for (uint64_t q = 0; q < Q; q++) {
		cin >> k;
		cout << digit_query(k) << endl;
	}
}
