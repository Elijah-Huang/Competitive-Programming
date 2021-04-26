#include <bits/stdc++.h>
using namespace std;

const int maxn = 3601, mod = 998244353;
long long ans = 0;
int h, w, n;
int dim[2];
long long tot[2];
long long dp[2][maxn][maxn]; // dp[k][i][j] = ways to choose pairs of empty rows/cols st
// 0-> row 1 -> column | up to pos | number of pairs chosen
bool taken[2][maxn]; // 0-> row 1 -> column

long long fact[maxn], invfact[maxn];

long long binexp(long long b, long long e) {
	b %= mod;
	long long ret = 1;
	while (e) {
		if (e & 1) {
			ret = (ret * b) % mod;
		}

		e >>= 1;
		b = (b * b) % mod;
	}
	
	return ret;
}

long long choose(int n, int k) {
	if (k > n) {
		return 0;
	}

	return (fact[n] * invfact[k] % mod)* invfact[n - k] % mod;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	// precompute factorials and inverse factorials
	fact[0] = 1;
	for (int i = 1; i < maxn; i++) {
		fact[i] = fact[i - 1] * i % mod;
	}

	invfact[maxn - 1] = binexp(fact[maxn - 1], mod - 2);
	for (int i = maxn - 2; i >= 0; i--) {
		invfact[i] = invfact[i + 1] * (i + 1) % mod;
	}

	cin >> h >> w >> n;

	dim[0] = h; dim[1] = w;

	for (int i = 0; i < n; i++) {
		int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2; 
		taken[0][r1] = taken[0][r2] = taken[1][c1] = taken[1][c2] = 1;
	}

	for (int k = 0; k < 2; k++) {
		for (int i = 1; i <= dim[k]; i++) {
			tot[k] += not taken[k][i];
		}
	}

	// dp
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i <= dim[k]; i++) {
			dp[k][i][0] = 1;
		}

		for (int i = 2; i <= dim[k]; i++) {
			for (int j = 1; 2 * j <= i; j++) {
				dp[k][i][j] = (dp[k][i - 1][j] + (taken[k][i] == taken[k][i - 1] and taken[k][i] == 0) * dp[k][i - 2][j - 1]) % mod;
			}
		}
	}

	// compute answer
	for (int v_dominos = 0; 2 * v_dominos <= tot[0]; v_dominos++) {
		for (int h_dominos = 0; 2 * h_dominos <= tot[1]; h_dominos++) {
			long long choose_rows = dp[0][dim[0]][v_dominos] * choose(tot[0] - 2 * v_dominos, h_dominos) % mod;
			long long choose_cols = dp[1][dim[1]][h_dominos] * choose(tot[1] - 2 * h_dominos, v_dominos) % mod;

			ans += ((choose_rows * choose_cols % mod) * fact[v_dominos] % mod) * fact[h_dominos] % mod;
		}
	}

	cout << ans % mod;
}