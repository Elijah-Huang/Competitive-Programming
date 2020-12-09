#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("wifi.in", "r", stdin); freopen("wifi.out", "w", stdout);
	int n, a, b;
	cin >> n >> a >> b;
	vector<int> locations(n);
	vector<double> dp(n + 1, 1 << 30);
	vector<vector<double>> cost(n, vector<double>(n,a));
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> locations[i];
	}
	sort(locations.begin(), locations.end());
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			cost[i][j] += (locations[j] - locations[i]) / 2.0 * b;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			dp[i] = min(dp[i], dp[j] + cost[j][i - 1]);
		}
	}
	if (fabs(int(dp[n]) - dp[n]) < 1e-8) {
		cout << int(dp[n]);
	}
	else {
		cout << fixed << setprecision(1) << dp[n];
	}
}