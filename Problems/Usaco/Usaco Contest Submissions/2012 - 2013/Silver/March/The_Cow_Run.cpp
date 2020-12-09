#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("cowrun.in", "r", stdin); freopen("cowrun.out", "w", stdout);
	int n;
	cin >> n;
	vector<int> locations(n);
	for (int i = 0; i < n; i++) {
		cin >> locations[i];
	}

	sort(locations.begin(), locations.end());
	int on_left = (lower_bound(locations.begin(), locations.end(), 0) - locations.begin());
	vector<vector<vector<int>>> dp(on_left + 1, vector<vector<int>>(n - on_left + 1, vector<int>(2)));
	if (on_left) {
		dp[1][0][0] = -locations[on_left - 1] * n;
		for (int i = on_left - 2; i >= 0; i--) {
			dp[on_left - i][0][0] = (locations[i + 1] - locations[i]) * (n - (on_left - i - 1)) + dp[on_left - i - 1][0][0];
		}
	}
	if (on_left < n) {
		dp[0][1][1] = locations[on_left] * n;
		for (int i = on_left + 1; i < n; i++) {
			dp[0][i - on_left + 1][1] = (locations[i] - locations[i - 1]) * (n - (i - on_left)) + dp[0][i - on_left][1];
		}
	}

	for (int r = 1; r <= n - on_left; r++) {
		for (int l = 1; l <= on_left; l++) {

			dp[l][r][1] = min(dp[l][r - 1][0] + (n - (l + r - 1)) * (locations[on_left + r - 1] - locations[on_left - l]),
				r > 1 ? dp[l][r - 1][1] + (n - (l + r - 1)) * (locations[on_left + r - 1] - locations[on_left + r - 2]) : 1 << 30);
			dp[l][r][0] = min(dp[l - 1][r][1] + (n - (l + r - 1)) * (locations[on_left + r - 1] - locations[on_left - l]),
				l > 1 ? dp[l - 1][r][0] + (n - (l + r - 1)) * (locations[on_left - l + 1] - locations[on_left - l]) : 1 << 30);
			
			dp[l][r][1] = min(dp[l][r][1], dp[l][r][0] + (n - (l + r)) * (locations[on_left + r - 1] - locations[on_left - l]));
			dp[l][r][0] = min(dp[l][r][0], dp[l][r][1] + (n - (l + r)) * (locations[on_left + r - 1] - locations[on_left - l]));

		}
	}

	cout << min(dp[on_left][n - on_left][0] == 0 ? 1 << 30 : dp[on_left][n - on_left][0],
		dp[on_left][n - on_left][1] == 0 ? 1 << 30 : dp[on_left][n - on_left][1]);
}