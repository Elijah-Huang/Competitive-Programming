#include<bits/stdc++.h>
using namespace std;

struct loc {
	int tot, mx;
};

loc dp[int(1e4)][int(1e3 + 1)];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("teamwork.in", "r", stdin); freopen("teamwork.out", "w", stdout);
	int ans = 0;
	int n, k; cin >> n >> k;
	vector<int> skills(n);
	for (int i = 0; i < n; i++) {
		cin >> skills[i];
	}

	loc worst = { -1e9,0 };
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = worst;
		}
	}
	dp[0][1] = { 0, skills[0] };
	for (int i = 0; i < n - 1; i++) {
		for (int j = 1; j < k; j++) {
			dp[i + 1][j + 1] = { max(dp[i + 1][j + 1].tot, dp[i][j].tot), max(dp[i][j].mx, skills[i + 1]) };
			dp[i + 1][1] = { max(dp[i + 1][1].tot, dp[i][j].tot + j * dp[i][j].mx), skills[i + 1]};
		}
		dp[i + 1][1] = { max(dp[i + 1][1].tot, dp[i][k].tot + k * dp[i][k].mx), skills[i + 1] };
	}

	for (int j = 1; j <= k; j++) {
		ans = max(ans, dp[n - 1][j].tot + j * dp[n - 1][j].mx);
	}

	cout << ans << '\n';
}