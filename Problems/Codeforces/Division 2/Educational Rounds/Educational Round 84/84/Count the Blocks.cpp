#include <bits/stdc++.h>
using namespace std;
long long powm(long long b, int p, int const& mod) {
	long long ans = 1;
	while (p) {
		if (p % 2 == 1) {
			ans = (ans * b) % mod;
		}
		p = p >> 1;
		b = (b * b) % mod;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0);
	int n;
	int ans;
	int mod = 998244353;
	int length;
	cin >> n;
	for (length = 1; length < n-1; length++) {
		ans = 0;
		ans = (ans + 2LL * 10 * 9 * powm(10LL, n - length - 1, mod)) % mod;
		ans = (ans + (n - length + 1 - 2) * (10LL * 9 * 9 * powm(10LL, n - length - 2, mod))) % mod;
		cout << ans << " ";
	}
	length = n - 1;
	if (length) {
		ans = (2LL * 10 * 9 * powm(10LL, n - length - 1, mod)) % mod;
		cout << ans << " ";
	}
	cout << 10;
}