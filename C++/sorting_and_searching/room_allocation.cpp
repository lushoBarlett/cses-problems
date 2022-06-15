#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <set>

using namespace std;

struct Customer {
	int id;
	int arrival;
	int leaving;
	
	bool operator!=(const Customer& b) const {
		return id != b.id;
	}
};

bool arrival_order(const Customer& a, const Customer& b) {
	return a.arrival < b.arrival;
}

bool leaving_order(const Customer& a, const Customer& b) {
	return a.leaving < b.leaving;
}

pair<int,vector<pair<int,int>>> rooms(vector<Customer>& customers) {
	// first is the customer id, second is the room used
	vector<pair<int,int>> rooms_used;

	vector<Customer> by_arrival = customers;
	vector<Customer> by_leaving = customers;

	sort(by_arrival.begin(), by_arrival.end(), arrival_order);
	sort(by_leaving.begin(), by_leaving.end(), leaving_order);

	// key: customer id
	// value: room id
	unordered_map<int,int> customer_occupation;
	set<int> free_rooms;

	int max_room_id = 0, room_id;

	// index one after the last person leaving
	auto customer = by_leaving.begin();
	for(const auto& new_customer : by_arrival) {
		// bye bye to everyone leaving before today
		while(new_customer != *customer and new_customer.arrival > customer->leaving) {
			int leaving_room = customer_occupation.find(customer->id)->second;
			free_rooms.insert(leaving_room);
			customer_occupation.erase(customer->id);
			customer++;
		}

		// select new room
		if (free_rooms.empty()) {
			max_room_id++;
			room_id = max_room_id;
		} else {
			room_id = *(free_rooms.rbegin());
			free_rooms.erase(room_id);
		}

		customer_occupation.insert({new_customer.id, room_id});
		rooms_used.push_back({new_customer.id, room_id});
	}
	
	sort(rooms_used.begin(), rooms_used.end());
	return {max_room_id, rooms_used};
}

int main() {
	int N, a, b;
	cin >> N;
	vector<Customer> n;
	for(int i = 0; i < N; i++) {
		cin >> a >> b;
		n.push_back({i, a, b});
	}

	auto answer = rooms(n);
	cout << answer.first << '\n';
	for(auto& a : answer.second)
		cout << a.second << ' ';
	cout << flush;
}
