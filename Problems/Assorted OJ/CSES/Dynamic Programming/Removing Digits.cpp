#include<bits/stdc++.h>
using namespace std;

int dp[int(1e6 + 1)];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;

	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int digit = 1; digit <= 9; digit++) {
			int j = i + digit, k = j;
			bool found = 0;
			while (k) {
				if (k % 10 == digit) {
					found = true;
					break;
				}
				k /= 10;
			}
			if (found) {
				dp[j] = min(dp[j], dp[i] + 1);
			}
		}
	}

	cout << dp[n];
}