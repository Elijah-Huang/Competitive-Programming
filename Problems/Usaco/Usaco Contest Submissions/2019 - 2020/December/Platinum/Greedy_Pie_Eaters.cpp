#include<bits/stdc++.h>
using namespace std;

const int maxn = 301;
int dp[maxn][maxn], mx_containing[maxn][maxn][maxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("pieaters.in","r",stdin); freopen("pieaters.out","w",stdout);
	
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int w, l, r; cin >> w >> l >> r;
		for (int j = l; j <= r; j++) {
			mx_containing[j][l][r] = max(mx_containing[j][l][r], w);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int l = i; l >= 1; l--) {
			for (int r = i; r <= n; r++) {
				if (l < i) {
					mx_containing[i][l][r] = max(mx_containing[i][l][r], mx_containing[i][l + 1][r]);
				}
				if (r > i) {
					mx_containing[i][l][r] = max(mx_containing[i][l][r], mx_containing[i][l][r - 1]);
				}
			}
		}
	}

	for (int l = n; l >= 1; l--) {
		for (int r = l; r <= n; r++) {
			// combining sets of cows
			for (int i = l; i < r; i++) {
				dp[l][r] = max(dp[l][r], dp[l][i] + dp[i + 1][r]);
			}

			// adding a new cow
			for (int i = l; i <= r; i++) {
				int new_weight = mx_containing[i][l][r];
				if (i > l) {
					new_weight += dp[l][i - 1];
				}
				if (i < r) {
					new_weight += dp[i + 1][r];
				}

				dp[l][r] = max(dp[l][r], new_weight);
			}
		}
	}
	
	cout << dp[1][n];
}