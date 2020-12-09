#include<bits/stdc++.h>
using namespace std;

int a[501];
int dp[501];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, x; cin >> n >> x;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		int last_idx = -1;
		for (int i = 0; i < n - 1; i++) {
			if (a[i] > a[i + 1]) {
				last_idx = i;
			}
		}
		if (last_idx == -1) {
			cout << 0 << '\n';
			continue;
		}

		memset(dp, 0xff, sizeof(dp));
		for (int i = 0; i < n-1 and a[i] >= a[i-1]; i++) {
			if (a[i] > x and (i == 0 or x >= a[i-1])) {
				if (a[i] > a[i + 1] and x > a[i+1]) {
					break;
				}
				dp[i] = 1;
			}
		}
		for (int i = 0; i < n - 1; i++) {
			if (dp[i] == -1) {
				continue;
			}

			int currx = a[i];
			for (int j = i + 1; j < n-1 and (j == (i+1) or a[j] >= a[j - 1]); j++) {
				if (a[j] > currx and (j == i+1 or currx >= a[j - 1])) {
					if (a[j] > a[j + 1] and currx > a[j + 1]) {
						break;
					}
					if (dp[j] == -1) {
						dp[j] = dp[i] + 1;
					}
					else {
						dp[j] = min(dp[j], dp[i] + 1);
					}
				}
			}
		}

		cout << dp[last_idx] << '\n';
	}
}