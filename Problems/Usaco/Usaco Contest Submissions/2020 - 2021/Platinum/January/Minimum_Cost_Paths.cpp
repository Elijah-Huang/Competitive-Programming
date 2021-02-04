#include<bits/stdc++.h>
using namespace std;

const int maxm = 2e5;
int n, m, q;
int c[maxm];

long long f(long long a, int j, int i) {
	return j * (a + 1) * (a + 1) + a * c[0] + (i - a) * c[j];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> c[i];
	}

	bool rev_sort = 1;
	for (int i = 1; i < m-1; i++) {
		if (c[i] < c[i + 1]) {
			rev_sort = 0;
		}
	}

	if (rev_sort) {
		cin >> q;
		while (q--) {
			int i, j; cin >> i >> j; i--; j--;

			int l = 0, r = min(i,int(2*sqrt(1e18/j)));
			if (f(0,j,i) <= f(1,j,i)) {
				l = r = 0;
			}
			
			while (l != r) {
				int d = (r - l) / 3;
				int m1 = l + d;
				int m2 = r - d;
				if (f(m1,j,i) > f(m2,j,i)) {
					l = m1 + 1;
				}
				else {
					r = m2 - 1;
				}
			}

			cout << f(l,j,i) << '\n';
		}
	}
	else {
		vector<vector<long long>> dp(n+1, vector<long long>(m+1,1e18));
		dp[1][0] = -1;
		for (long long i = 1; i <= n; i++) {
			for (long long j = 1; j <= m; j++) {
				dp[i][j] = min(dp[i - 1][j] + c[j - 1], dp[i][j - 1] + i * i);
			}
		}

		cin >> q;
		while (q--) {
			int i, j; cin >> i >> j;
			cout << dp[i][j] << '\n';
		}
	}
}