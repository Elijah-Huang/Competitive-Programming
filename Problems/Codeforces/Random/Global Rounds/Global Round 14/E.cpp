#include <bits/stdc++.h>
using namespace std;

//POWM IS NEEDED!
const int maxn = 402;
long long fac[maxn];
long long inv_fac[maxn];
int mod = 0;

long long powm(long long b, long long e, int const& mod) {
	b %= mod;

	long long ans = 1;

	while (e) {
		if (e & 1) {
			ans = (ans * b) % mod;
		}

		e = e >> 1;
		b = (b * b) % mod;
	}

	return ans;
}

void choose_setup() {
	fac[0] = 1;
	for (int i = 1; i < maxn; i++) {
		fac[i] = fac[i - 1] * i % mod;
	}

	inv_fac[maxn-1] = powm(fac[maxn-1], mod - 2, mod);
	for (int i = maxn-2; i >= 0; i--) {
		inv_fac[i] = inv_fac[i + 1] * (i + 1) % mod;
	}
}

long long choose(int n, int k) {
	return (fac[n] * inv_fac[n - k] % mod) * inv_fac[k] % mod;
}

long long dp[maxn][maxn], dp2[maxn][maxn][2], tot[maxn];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m; cin >> n >> m;
	mod = m;

	choose_setup();

	dp2[1][1][0] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int j2 = j+1; j2 <= i+1; j2++) {
				dp2[i + 1][j2][1] = (dp2[i + 1][j2][1] + dp2[i][j][1]) % mod;
			}

			for (int j2 = 1; j2 <= j; j2++) {
				dp2[i + 1][j2][0] = (dp2[i + 1][j2][0] + dp2[i][j][0]) % mod;
			}
			for (int j2 = j+1; j2 <= i+1; j2++) {
				dp2[i + 1][j2][1] = (dp2[i + 1][j2][1] + dp2[i][j][0]) % mod;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			tot[i] += dp2[i][j][0] + dp2[i][j][1];
		}
		tot[i] %= mod;
	}

	dp[0][0] = 1;
	for (int i = 0; i <= n-1; i++) {
		for (int j = 0; j <= n; j++) {
			for (int i2 = i + 2; i2 <= n+1; i2++) {
				int added = i2 - i - 1;
				dp[i2][j + added] = (dp[i2][j + added] + (dp[i][j] * tot[added] % mod) * choose(j + added, added) % mod) % mod;
			}
		}
	}

	long long ans = 0;
	for (int j = 1; j <= n; j++) {
		ans += dp[n + 1][j];
	}

	cout << ans % mod;
}