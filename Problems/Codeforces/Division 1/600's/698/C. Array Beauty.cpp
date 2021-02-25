#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e3, maxa = 1e5, mod = 998244353;
int n, k;
int a[maxn+1];
// last pos of element in sequencce | length of sequence
int dp[maxn+1][maxn+1], dp_tot[maxn+1][maxn+1];
int ans = 0;

// dist >= this
int solve(int x) {
	int l_ptr = 0;
	// reset
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j] = dp_tot[i][j] = 0;
		}
	}
	// base case
	for (int i = 1; i <= n; i++) {
		dp[i][1] = 1;
		dp_tot[i][1] = i;
	}

	for (int i = 1; i <= n; i++) {
		while (l_ptr < n and a[i] - a[l_ptr + 1] >= x) {
			l_ptr++;
		}

		// can't even add 2nd element
		if (l_ptr == 0 or a[i] - a[l_ptr] < x) {
			continue;
		}

		// update psums
		for (int j = 2; j <= k; j++) {
			dp_tot[i][j] = dp_tot[i - 1][j];
		}

		// transition + update psums
		for (int j = 2; j <= k; j++){
			dp[i][j] = dp_tot[l_ptr][j - 1];
			dp_tot[i][j] = (dp_tot[i][j] + dp[i][j]) % mod;
		}
	}

	return dp_tot[n][k];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
		
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	sort(a+1, a + n+1);
	
	for (int i = 1; i <= maxa / (k - 1); i++) {
		ans = (ans + solve(i)) % mod;
	}

	cout << ans;
}