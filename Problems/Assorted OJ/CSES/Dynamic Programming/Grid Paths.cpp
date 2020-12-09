#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
vector<string> grid(1000);
unsigned int dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}

	if (grid[0][0] == '.') {
		dp[1][1] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (grid[i - 1][j - 1] == '.') {
				dp[i][j] = (dp[i][j] + dp[i - 1][j] + dp[i][j - 1]) % mod;
			}
		}
	}

	cout << dp[n][n];
}