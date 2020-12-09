#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int dp[2][65000];

long long powm(long long base, int exp) {
	base %= mod;
	long long ans = 1;

	while (exp) {
		if (exp & 1) {
			ans = (ans * base) % mod;
		}
		exp >>= 1;
		base = (base * base) % mod;
	}
	
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;

	if (n % 4 != 0 and (n + 1) % 4 != 0) {
		cout << 0;
		return 0;
	}

	dp[0][0] = 1;
	for (int num = 1; num <= n; num++) {
		for (int i = 0; i < 65000 - num; i++) {
			dp[1][i + num] = dp[0][i];
		}

		for (int i = 0; i <= 65000; i++) {
			dp[0][i] = (dp[0][i] + dp[1][i]) % mod;
			dp[1][i] = 0;
		}
	}

	cout << (dp[0][n * (n + 1) / 4] * powm(2, mod - 2)) % mod;
}