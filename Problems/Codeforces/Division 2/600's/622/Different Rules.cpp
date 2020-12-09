#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	int t, n, x, y;
	cin >> t;
	while (t--) {
		cin >> n >> x >> y;
		if ((x + y) <= n) {
			cout << 1 << ' ';
		}
		else {
			cout << min(x + y + 1 - n, n) << ' ';
		}
		if ((x + y) >= n + 1) {
			cout << n << '\n';
		}
		else {
			cout << x + y - 1 << '\n';
		}
	}
}