// O(N*P*K)
#include<bits/stdc++.h>
using namespace std;

const int maxn = 51, maxk = 31, maxp = 50 * 30 + 1;
int dp[maxn][maxp];
int beauty[maxn][maxk];
int t, n, k, p;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;

	for (int i = 1; i <= t; i++) {
		cin >> n >> k >> p;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k; j++) {
				cin >> beauty[i][j];
			}
		}

		memset(dp, 0xdf, sizeof(dp));
		dp[0][p] = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= p; j++) {
				int tot_beauty = 0;
				for (int used = 0; used <= min(k,j); used++) {
					dp[i + 1][j - used] = max(dp[i + 1][j - used], dp[i][j] + tot_beauty);
					tot_beauty += beauty[i][used];
				}
			}
		}


		cout << "Case #" << i << ": " << dp[n][0] << '\n';
	}
}