#include<bits/stdc++.h>
using namespace std;

int n, k;
pair<int,int> p[600];
long long dp[600][51];
long long ans = 0;

int main() {
	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}

	sort(p, p + n);

	memset(dp, 0x80, sizeof(dp));
	for (int i = 0; i < n; i++) {
		dp[i][1] = 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 1; j < k; j++) {
			for (int i2 = i + 1; i2 < n; i2++) {
				dp[i2][j + 1] = max(dp[i2][j + 1], dp[i][j] + abs(p[i].first - p[i2].first) + abs(p[i].second - p[i2].second));
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans;
}