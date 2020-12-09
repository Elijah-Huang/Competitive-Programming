#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		long long x, y; cin >> y >> x;
		long long ans = (max(x,y) - 1) * (max(x,y) - 1);
		if (x < y) {
			ans += (y % 2 == 0 ? 2 * y - 1 - (x - 1): x);
		}
		else {
			ans += (x % 2 == 1 ? 2 * x - 1 - (y - 1) : y);
		}
		cout << ans << '\n';
	}
}