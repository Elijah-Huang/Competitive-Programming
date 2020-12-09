#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int x, n; cin >> x >> n;

	multiset<int,greater<int>> lengths = { x };
	set<int> traffic_lights = { 0,x };
	while (n--) {
		int p; cin >> p;

		auto up = traffic_lights.lower_bound(p);
		auto bottom = up; bottom--;
		lengths.erase(lengths.find(*up - *bottom));
		traffic_lights.insert(p);
		lengths.insert(*up - p);
		lengths.insert(p - *bottom);

		cout << *lengths.begin() << ' ';
	}
}