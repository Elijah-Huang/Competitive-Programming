#include<bits/stdc++.h>
using namespace std;

int t, n;
const int maxn = 1e6 + 1, mod = 1e9 + 7;
long long dp[maxn];
long long psum = 1;

int main() {
	dp[0] = 1, dp[1] = 2;
	for (int i = 2; i < maxn; i++) {
		// transition from last state + all transitions from states before that
		dp[i] = (2 * dp[i - 1] + (3 * dp[i - 1] - 2 * psum + 2*mod)) % mod;
		psum = (psum + dp[i - 1]) % mod;
	}

	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n] << '\n';
	}
}
