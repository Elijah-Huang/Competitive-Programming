#include<bits/stdc++.h>
using namespace std;

struct customer {
	int a, b, i;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<customer> customers(n);
	vector<int> rooms(n);
	for (int i = 0; i < n; i++) {
		cin >> customers[i].a >> customers[i].b;
		customers[i].i = i;
	}

	auto cmp = [&](const customer& a, const customer& b) {return a.a < b.a; };
	sort(customers.begin(), customers.end(), cmp);

	set<pair<int, int>,greater<pair<int,int>>> active_rooms;
	for (int i = 0; i < n; i++) {
		auto loc = active_rooms.upper_bound({ customers[i].a,0 });
		if (loc == active_rooms.end()) {
			active_rooms.insert({ customers[i].b,active_rooms.size() + 1 });
			rooms[customers[i].i] = active_rooms.size();
		}
		else {
			active_rooms.insert({ customers[i].b, loc->second });
			rooms[customers[i].i] = loc->second;
			active_rooms.erase(loc);
		}
	}
	
	cout << active_rooms.size() << '\n';
	for (auto i : rooms) {
		cout << i << ' ';
	}
}