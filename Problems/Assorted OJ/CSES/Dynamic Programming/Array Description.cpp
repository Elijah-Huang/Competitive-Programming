#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int dp[int(1e5)][101];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	vector<int> values(n);
	for (int i = 0; i < n; i++) {
		cin >> values[i];
	}
	
	if (values[0] == 0) {
		for (int i = 1; i <= m; i++) {
			dp[0][i] = 1;
		}
	}
	else {
		dp[0][values[0]] = 1;
	}
	for (int i = 1; i < n; i++) {
		if (values[i] == 0) {
			for (int val = 1; val <= m; val++) {
				if ((i == 0 or abs(values[i - 1] - val) <= 1 or values[i - 1] == 0 and
					i == n - 1 or abs(values[i + 1] - val) <= 1 or values[i + 1] == 0)) {
					for (int j = max(1, val - 1); j <= min(m, val + 1); j++) {
						dp[i][val] = (dp[i][val] + dp[i - 1][j]) % mod;
					}
				}
			}
		}
		else {
			for (int j = max(1, values[i] - 1); j <= min(m, values[i] + 1); j++) {
				dp[i][values[i]] = (dp[i][values[i]] + dp[i - 1][j]) % mod;
			}
		}
	}

	int ans = 0;
	if (values[n-1] == 0) {
		for (int i = 1; i <= m; i++) {
			ans = (ans + dp[n - 1][i]) % mod;
		}
	}
	else {
		ans = dp[n - 1][values[n - 1]];
	}

	cout << ans;
}