#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("empty.in", "r", stdin); freopen("empty.out", "w", stdout);
	int n, k; cin >> n >> k;
	set<int> st;
	for (int i = 0; i < n; i++) {
		st.insert(i);
	}
	while (k--) {
		int x, y, a, b; cin >> x >> y >> a >> b;
		int loc = b;
		for (int i = 0; i < y; i++) {
			loc = (a + loc) % n;
			for (int j = 0; j < x; j++) {
				auto pos = st.lower_bound(loc);
				if (pos != st.end()) {
					st.erase(pos);
				}
				else {
					st.erase(st.begin());
				}
			}
		}
	}

	cout << *st.begin();
}