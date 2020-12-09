#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("hopscotch.in", "r", stdin); freopen("hopscotch.out", "w", stdout);
	int r, c, k; cin >> r >> c >> k;
	vector<vector<int>> grid(r, vector<int>(c));
	vector<vector<int>> dp(r, vector<int>(c,-1));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> grid[i][j];
		}
	}

	dp[0][0] = 1;
	const int mod = 1e9 + 7;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (dp[i][j] != -1) {
				for (int i2 = i + 1; i2 < r; i2++) {
					for (int j2 = j + 1; j2 < r; j2++) {
						if (grid[i][j] != grid[i2][j2]) {
							if (dp[i2][j2] == -1) {
								dp[i2][j2] = dp[i][j];
							}
							else {
								dp[i2][j2] = (dp[i2][j2] + dp[i][j]) % mod;
							}
						}
					}
				}
			}
		}
	}

	cout << dp[r - 1][c - 1];
}