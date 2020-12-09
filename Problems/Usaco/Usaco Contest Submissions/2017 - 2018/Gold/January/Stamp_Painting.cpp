#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
long long dp[int(1e6)][2];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("spainting.in", "r", stdin); freopen("spainting.out", "w", stdout);
	int n, m, k; cin >> n >> m >> k;
	long long uncomplete0 = 0, uncomplete1 = 0, complete_tot = 0;

	for (int i = 0; i < k - 1; i++) {
		dp[i][0] = m;
	}
	for (int i = k - 1; i < n; i++) {
		dp[i][1] = m;
	}
	for (int i = 1; i < n; i++) {
		uncomplete1 += dp[i - 1][0];
		if (i >= k) {
			uncomplete1 -= dp[i - k][0];
			uncomplete0 = (uncomplete0 + dp[i - k][0]) % mod;
		}
		uncomplete1 = (uncomplete1 + mod) % mod;
		complete_tot = (complete_tot + dp[i - 1][1]) % mod;
		dp[i][0] = (dp[i][0] + (m - 1) * uncomplete1) % mod;
		dp[i][1] = (dp[i][1] + (m - 1) * (complete_tot + uncomplete0)) % mod;
	}

	cout << dp[n - 1][1] << '\n';
}