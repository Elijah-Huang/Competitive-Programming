// O(n*m*k)
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1001, maxk = 11, mod = 1e9 + 9;
int n, m, k;
int john[maxn], paul[maxn];
// | last cow of farmer j in pairing <= this idx | last cow of farmer p in pairing <= this idx | k pairs chosen |
unsigned int dp[maxn][maxn][maxk];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("team.in", "r", stdin); freopen("team.out", "w", stdout);
	
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		cin >> john[i];
	}

	for (int i = 1; i <= m; i++) {
		cin >> paul[i];
	}
	
	sort(john + 1, john + n + 1);
	sort(paul + 1, paul + m + 1);

	for (int p = 1; p <= k; p++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				// number of pairs of length p-1 that end before i and j (if we can add a new pair) +
				// number of pairs of length p that end up to i or j but not at both (use PIE)
				dp[i][j][p] = (((john[i] > paul[j]) * ((p == 1) + dp[i - 1][j - 1][p-1])) +
					(dp[i][j - 1][p] + dp[i - 1][j][p] + mod - dp[i - 1][j - 1][p])) % mod;
			}
		}
	}

	cout << dp[n][m][k];
}