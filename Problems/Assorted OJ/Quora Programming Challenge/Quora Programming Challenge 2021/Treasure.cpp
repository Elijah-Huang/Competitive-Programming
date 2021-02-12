#include<bits/stdc++.h>
using namespace std;

int n;
const int maxn = 1001, mod = 1e9 + 7;
int dp[maxn][maxn];
long long ways[maxn][maxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		string a; cin >> a;
		for (int j = 1; j <= n; j++) {
			dp[i][j] = (a[j - 1] - '0');
		}
	}

	ways[0][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j - 1] == dp[i - 1][j]) {
				dp[i][j] += dp[i][j - 1];
				ways[i][j] = (ways[i][j - 1] + ways[i - 1][j]) % mod;
			}
			else if (dp[i][j - 1] > dp[i - 1][j]) {
				dp[i][j] += dp[i][j - 1];
				ways[i][j] = ways[i][j - 1];
			}
			else {
				dp[i][j] += dp[i - 1][j];
				ways[i][j] = ways[i - 1][j];
			}
		}
	}

	cout << dp[n][n] << ' ' << ways[n][n];
}