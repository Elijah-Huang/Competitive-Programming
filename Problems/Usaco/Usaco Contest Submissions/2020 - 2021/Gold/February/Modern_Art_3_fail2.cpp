#include<bits/stdc++.h>
using namespace std;

const int maxn = 300;
int n, a[maxn];
// dp[L][R] minimum strokes to paint the subpainting L->R
int dp[maxn][maxn];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	memset(dp, 0x1f, sizeof(dp));

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i]; a[i]--;
		dp[i][i] = 1;
	}


	for (int r = 0; r < n; r++) {
		for (int l = r; l >= 0; l--) {
			if (r < n - 1) {
				// new stroke
				dp[l][r + 1] = min(dp[l][r + 1], dp[l][r] + 1);
				// continue stroke
				if (a[l] == a[r + 1] or a[r] == a[r + 1]) {
					dp[l][r + 1] = min(dp[l][r + 1], dp[l][r]);
				}
			}

			if (l > 0) {
				// new stroke
				dp[l - 1][r] = min(dp[l - 1][r], dp[l][r] + 1);
				// continue stroke
				if (a[r] == a[l - 1] or a[l] == a[l - 1]) {
					dp[l - 1][r] = min(dp[l - 1][r], dp[l][r]);
				}
			}
		}
	}

	cout << dp[0][n-1];
}