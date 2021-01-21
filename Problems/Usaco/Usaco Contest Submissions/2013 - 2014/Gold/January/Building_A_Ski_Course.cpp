#include<bits/stdc++.h>
using namespace std;

const int maxn = 100;
int n, m, ans = maxn;
// 0 = R, 1 = S
bool type[maxn][maxn][2];
//dp[i][j][k] = largest square of type k with top left corner i,j
int dp[maxn+1][maxn+1][2];
string row;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("skicourse.in", "r", stdin); freopen("skicourse.out", "w", stdout);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> row;

		for (int j = 0; j < m; j++) {
			if (row[j] == 'R') {
				type[i][j][0] = 1;
			}
			else {
				type[i][j][1] = 1;
			}
		}
	}

	while (true) {
		int mx_len = 0, best_i, best_j;
		
		memset(dp, 0, sizeof(dp));
		for (int i = n-1; i >= 0; i--) {
			for (int j = m-1; j >= 0; j--) {
				for (int k = 0; k < 2; k++) {
					dp[i][j][k] = (type[i][j][k]) * (min({ dp[i + 1][j][k], dp[i][j + 1][k],dp[i + 1][j + 1][k] }) + 1);
				}

				if (dp[i][j][0] != dp[i][j][1] and mx_len < max(dp[i][j][0], dp[i][j][1])) {
					mx_len = max(dp[i][j][0], dp[i][j][1]);
					best_i = i;
					best_j = j;
				}
			}
		}

		if (mx_len == 0) {
			break;
		}
		
		ans = min(ans, mx_len);

		for (int i = best_i; i < best_i + mx_len; i++) {
			for (int j = best_j; j < best_j + mx_len; j++) {
				for (int k = 0; k < 2; k++) {
					type[i][j][k] = 1;
				}
			}
		}
	}

	cout << ans;
}