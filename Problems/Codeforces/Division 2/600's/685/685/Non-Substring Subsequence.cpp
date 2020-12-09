#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, q; cin >> n >> q;
		string s; cin >> s;
		while (q--) {
			int l, r; cin >> l >> r;
			l--; r--;
			bool worked = false;

			for (int bad = l; bad <= r; bad++) {
				int idx = l;
				for (int i = 0; i < n; i++) {
					if (idx == r + 1) {
						break;
					}
					if (i == bad) {
						continue;
					}

					if (s[i] == s[idx]) {
						idx++;
					}
				}

				if (idx == r + 1) {
					worked = true;
					break;
				}
			}

			if (worked) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}
}