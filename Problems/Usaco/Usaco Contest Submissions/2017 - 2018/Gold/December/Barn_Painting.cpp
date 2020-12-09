#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
vector<vector<int>> adj(1e5);
long long dp[(int)1e5][3];

void solve(int curr, int parent) {
	for (auto child : adj[curr]) {
		if (child == parent) continue;
		solve(child, curr);
		for (int c = 0; c <= 2; c++) {
			dp[curr][c] = (dp[curr][c]*(dp[child][(c + 1)%3] + dp[child][(c + 2)%3]))%mod;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("barnpainting.in", "r", stdin); freopen("barnpainting.out", "w", stdout);
	int n, k; cin >> n >> k;
	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			dp[i][j] = 1;
		}
	}
	for (int i = 0; i < k; i++) {
		int b, c; cin >> b >> c; b--;
		dp[b][c % 3] = dp[b][(c + 1) % 3] = 0;
	}

	solve(0, -1);
	cout << (dp[0][0] + dp[0][1] + dp[0][2]) % mod<< '\n';
}