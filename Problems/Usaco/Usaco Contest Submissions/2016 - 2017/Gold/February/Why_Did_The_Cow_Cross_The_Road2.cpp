#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("nocross.in", "r", stdin); freopen("nocross.out", "w", stdout);
	int n; cin >> n;
	vector<vector<int>> cows(2, vector<int>(n));
	for (int i = 0; i < 2 * n; i++) {
		cin >> cows[i / n][i % n];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = max({ dp[i - 1][j], dp[i][j - 1] , dp[i - 1][j - 1] + (abs(cows[0][i - 1] - cows[1][j - 1]) <= 4) });
		}
	}

	cout << dp[n][n];
}