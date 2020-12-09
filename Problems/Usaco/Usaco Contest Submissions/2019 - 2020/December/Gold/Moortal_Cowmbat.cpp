#include<bits/stdc++.h>
using namespace std;

int dp[int(1e5 + 1)][26], cost[int(1e5 + 1)][26];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("cowmbat.in", "r", stdin); freopen("cowmbat.out", "w", stdout);
	int n, m, k; cin >> n >> m >> k;
	string s; cin >> s;
	vector<vector<int>> dist(m, vector<int>(m));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> dist[i][j];
		}
	}
	 
	for (int k = 0; k < m; k++) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for (int i = 0; i < s.length(); i++) {
		for (int c = 0; c < m; c++) {
			cost[i + 1][c] = cost[i][c] + dist[s[i]-'a'][c];
		}
	}

	memset(dp, 0x3f, sizeof(dp));
	for (int c = 0; c < m; c++) {
		dp[k][c] = cost[k][c];
	}
	for (int loc = k; loc <= s.length()-1; loc++) {
		for (int c = 0; c < m; c++) {
			for (int c2 = 0; c2 < m; c2++) {
				if (c == c2) {
					dp[loc + 1][c2] = min(dp[loc + 1][c2], dist[s[loc]-'a'][c2] + dp[loc][c2]);
				}
				else if (loc + k <= s.length()) {
					dp[loc + k][c2] = min(dp[loc + k][c2], cost[loc + k][c2] - cost[loc][c2] + dp[loc][c]);
				}
			}
		}
	}

	int ans = 1e9;
	for (int c = 0; c < m; c++) {
		ans = min(ans, dp[s.length()][c]);
	}
	
	cout << ans << '\n';
}