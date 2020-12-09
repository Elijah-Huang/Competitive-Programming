#include<bits/stdc++.h>
using namespace std;

int dp[501][1000];
int moonies[1000];
vector<int> adj[1000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("time.in", "r", stdin); freopen("time.out", "w", stdout);
	int n, m, c; cin >> n >> m >> c;
	for (int i = 0; i < n; i++) {
		cin >> moonies[i];
	}
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		u--; v--;
		adj[v].push_back(u);
	}

	memset(dp, 0xe0, sizeof(dp));
	dp[0][0] = 0;
	for (int t = 1; t <= 500; t++) {
		for (int i = 0; i < n; i++) {
			for (auto j : adj[i]) {
				dp[t][i] = max(dp[t][i], dp[t - 1][j] + moonies[i]);
			}
		}
	}

	int ans = 0;
	for (int t = 0; t <= 500; t++) {
		ans = max(ans, dp[t][0] - c * t * t);
	}

	cout << ans;
}