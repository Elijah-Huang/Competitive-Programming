// O(n^3)
#include<bits/stdc++.h>
using namespace std;

const int maxn = 300;
int n, a[maxn];
int dp[maxn][maxn];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int r = 1; r < n; r++) {
		for (int l = r - 1; l >= 0; l--) {
			// add segment
			if (a[l] == a[r]) {
				dp[l][r] = max(dp[l][r], dp[l + 1][r - 1] + 1);
			}

			// join 2 different sets of segments
			// note that they can share a common point
			for (int m = l + 1; m < r; m++) {
				dp[l][r] = max(dp[l][r], dp[l][m] + dp[m][r]);
			}
		}
	}

	cout << n - dp[0][n - 1];
}