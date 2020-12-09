#include<bits/stdc++.h>
using namespace std;

long long ans = 1ll << 62;
long long a[1001];
long long dp[1001][1001][2];
long long change[1001][1001][2];
long long prefix_mn[1002][2], suffix_mn[1002][2];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		change[i][1][0] = ((k + 1) - a[i]) % (k + 1);
		change[i][1][1] = a[i];
		for (int j = 2; j <= n; j++) {
			change[i][j][0] = change[i][j - 1][0] + k + 1;
			change[i][j][1] = change[i][j - 1][1] + k + 1;
		}
	}

	for (int j = 1; j <= n; j++) {
		for (int k = 0; k < 2; k++) {
			dp[1][j][k] = change[1][j][k];
		}
	}
	for (int i = 2; i <= n; i++) {
		suffix_mn[n + 1][0] = suffix_mn[n + 1][1] = prefix_mn[0][0] = prefix_mn[0][1] = 1ll << 62;
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < 2; k++) {
				suffix_mn[n + 1 - j][k] = min(suffix_mn[n + 2 - j][k], dp[i - 1][n + 1 - j][k]);
				prefix_mn[j][k] = min(prefix_mn[j - 1][k], dp[i - 1][j][k] - change[i - 1][j][k]);
			}
		}

		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < 2; k++) {
				dp[i][j][k] = suffix_mn[1][k ^ 1] + change[i][j][k];
				dp[i][j][k] = min({ dp[i][j][k], change[i][j][k] + prefix_mn[j - 1][k], dp[i - 1][j][k] + max(0ll,change[i][j][k] - change[i - 1][j][k]), suffix_mn[j + 1][k] });
			}
			
		}
	}

	for (int j = 1; j <= n; j++) {
		for (int k = 0; k < 2; k++) {
			ans = min(ans, dp[n][j][k]);
		}
	}

	cout << ans;
}