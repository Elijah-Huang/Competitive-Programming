#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		long long base = (n - m) / (m + 1);
		long long ans = (long long)n * (n + 1) / 2;
		int other = (n - m) % (m + 1);
		ans -= base * (base + 1) / 2 * (m + 1 - other);
		ans -= (base + 1) * (base + 2) / 2 * (other);
		cout << ans << '\n';
	}
}