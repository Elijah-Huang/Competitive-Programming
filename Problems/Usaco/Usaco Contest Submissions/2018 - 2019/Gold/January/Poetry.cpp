#include<bits/stdc++.h>
using namespace std;

int dp[5001];
const int mod = 1e9 + 7;

long long powm(long long base, int exp) {
	long long res = 1;
	while (exp) {
		if (exp & 1) {
			res = (res * base) % mod;
		}
		exp >>= 1;
		base = (base * base) % mod;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("poetry.in", "r", stdin); freopen("poetry.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	dp[0] = 1;
	vector<int> lengths;
	vector<vector<int>> types(n);
	vector<long long> one_line(n);
	vector<int> amts(26);
	for (int i = 0; i < n; i++) {
		int l, t; cin >> l >> t;
		t--;
		lengths.push_back(l);
		types[t].push_back(l);
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			if (i + lengths[j] <= k) {
				dp[i + lengths[j]] = (dp[i + lengths[j]] + dp[i]) % mod;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		char a; cin >> a;
		amts[a - 'A']++;
	}

	for (int i = 0; i < n; i++) {
		for (auto l : types[i]) {
			one_line[i] = (one_line[i] + dp[k - l]) % mod;
		}
	}

	long long ans = 1;
	for (auto amt : amts) {
		if (amt) {
			int a = 0;
			for (auto ways : one_line) {
				if (ways) {
					a = (a + powm(ways, amt)) % mod;
				}
			}
			ans = (ans * a) % mod;
		}
	}

	cout << ans;
}