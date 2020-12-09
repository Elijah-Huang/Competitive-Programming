#include<bits/stdc++.h>
using namespace std;

int dp[501][501];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a, b; cin >> a >> b;

	memset(dp, 0x3f, sizeof(dp));
	for (int i = 0; i <= 500; i++) {
		dp[i][i] = 0;
	}
	
	for (int i = 1; i <= 500; i++) {
		for (int j = 1; j <= i; j++) {
			for (int horiz = 1; horiz < i; horiz++) {
				dp[i][j] = min(dp[i][j], 1 + dp[horiz][j] + dp[i - horiz][j]);
			}
			for (int vert = 1; vert < j; vert++) {
				dp[i][j] = min(dp[i][j], 1 + dp[i][vert] + dp[i][j - vert]);
			}
			dp[j][i] = dp[i][j];
		}
	}

	cout << dp[a][b];
}