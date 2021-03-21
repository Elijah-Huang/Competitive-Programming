#include<bits/stdc++.h>
using namespace std;

const int maxn = 501;
// 0 -> row maxes 1 -> col
int mx[2][maxn][maxn], a[maxn][maxn], b[maxn][maxn], dp[maxn][maxn];
int t, n;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;

	for (int i = 1; i <= t; i++) {
		int tot = 0;

		cin >> n;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> b[i][j];
				tot += b[i][j];
			}
		}

		// don't need R or C
		for (int i = 0; i < 2 * n; i++) {
			int c; cin >> c;
		}


		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				mx[0][i][j] = max(mx[0][i][j - 1], b[i][j]);
			}
		}

		for (int j = 1; j <= n; j++) {
			for (int i = 1; i <= n; i++) {
				mx[1][i][j] = max(mx[1][i - 1][j], b[i][j]);
			}
		}


		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j] = max(dp[i - 1][j] + mx[0][i][j], dp[i][j - 1] + mx[1][i][j]);
				cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
			}
		}

		cout << "Case #" << i << ": " << tot - dp[n][n] << '\n';
	}
}