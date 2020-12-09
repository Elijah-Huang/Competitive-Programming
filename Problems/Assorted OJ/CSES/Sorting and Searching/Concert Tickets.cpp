#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	multiset<int> h; 
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		h.insert(a);
	}

	while (m--) {
		int mx; cin >> mx;
		auto loc = h.upper_bound(mx);
		if (loc == h.begin()) {
			cout << -1 << '\n';
		}
		else {
			--loc;
			cout << *loc << '\n';
			h.erase(loc);
		}
	}
}