#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	int q, n, a[200000], o[200000], i, curr;
	set<int> b;
	bool gap;
	cin >> q;
	while (q--) {
		b.clear();
		cin >> n;
		for (i = 0; i < n; i++) {
			cin >> a[i];
			b.insert(a[i]);
		}
		if (b.size() == 1) {
			cout << 1 << '\n';
			for (i = 0; i < n; i++) {
				cout << 1 << " ";
			}
		}
		else if (n % 2 == 0) {
			cout << 2 << '\n';
			for (i = 0; i < n; i++) {
				cout << 1 + (i % 2) << " ";
			}
		}
		else {
			gap = false;
			curr = 2;
			a[n] = a[0];
			for (i = 0; i < n; i++) {
				if (i >= 1 and not gap and a[i] == a[i - 1]) {
					o[i] = curr;
					gap = true;
				}
				else if (i == n - 1 and not gap) {
					if (a[n - 1] == a[0]) {
						gap = true;
						o[n - 1] = o[0];
					}
					else {
						o[n - 1] = 3;
					}
				
				}
				else {
					curr = 1 + (curr) % 2;
					o[i] = curr;
				}
			}
			if (gap) {
				cout << 2 << '\n';
				for (i = 0; i < n; i++) {
					cout << o[i] << " ";
				}
				cout << '\n';
			}
			else {
				cout << 3 << '\n';
				for (i = 0; i < n; i++) {
					cout << o[i] << " ";
				}
				cout << '\n';
			}
		}
	}
}