#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	multiset<int> towers;
	while (n--) {
		int a; cin >> a;
		auto loc = towers.upper_bound(a);
		if (loc == towers.end()) {
			towers.insert(a);
		}
		else {
			towers.erase(loc);
			towers.insert(a);
		}
	}

	cout << towers.size();
}