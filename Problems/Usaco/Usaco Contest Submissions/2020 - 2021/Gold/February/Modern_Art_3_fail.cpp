#include<bits/stdc++.h>
using namespace std;

const int maxn = 300;
int n, a[maxn];
// dp[L][R][B] minimum strokes to paint the subpainting L->R with bottom color B
int dp[maxn][maxn][maxn];
int ans = maxn + 1;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	memset(dp, 0x1f, sizeof(dp));

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i]; a[i]--;
		dp[i][i][a[i]] = 1;
	}


	for (int r = 0; r < n; r++) {
		for (int l = r; l >= 0; l--) {
			for (int b = 0; b < n; b++) {
				if (r < n - 1) {
					// expand bottom color
					if (b == a[r + 1]) {
						dp[l][r + 1][b] = min(dp[l][r + 1][b], dp[l][r][b]);
					}
					// expand right side
					if (a[r] == a[r + 1]) {
						dp[l][r + 1][b] = min(dp[l][r + 1][b], dp[l][r][b]);
					}
					// paint new color
					dp[l][r + 1][b] = min(dp[l][r + 1][b], dp[l][r][b] + 1);
					
					// change bottom color
					dp[l][r + 1][a[r + 1]] = min(dp[l][r + 1][a[r + 1]], dp[l][r + 1][b]);
					dp[l][r + 1][a[l]] = min(dp[l][r + 1][a[l]], dp[l][r + 1][b]);
				}

				if (l > 0) {
					// expand bottom color
					if (b == a[l - 1]) {
						dp[l - 1][r][b] = min(dp[l - 1][r][b], dp[l][r][b]);
					}
					// expand left side
					if (a[l] == a[l - 1]) {
						dp[l - 1][r][b] = min(dp[l - 1][r][b], dp[l][r][b]);
					}
					// paint new color
					dp[l - 1][r][b] = min(dp[l - 1][r][b], dp[l][r][b] + 1);

					// change bottom color
					dp[l - 1][r][a[l - 1]] = min(dp[l - 1][r][a[l - 1]], dp[l - 1][r][b]);
					dp[l - 1][r][a[r]] = min(dp[l - 1][r][a[r]], dp[l - 1][r][b]);
				}
			}
		}
	}
	

	for (int i = 0; i < n; i++) {
		ans = min(ans, dp[0][n - 1][i]);
	}

	cout << ans;
}