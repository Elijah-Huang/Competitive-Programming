#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	int n, h, l, r, a[2000], dp[2001][2000]{};
	cin >> n >> h >> l >> r;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	dp[0][0] = 1;
	int new_time1, new_time2,good;
	for (int sleep_time = 0; sleep_time <= n-1; sleep_time++) {
		for (int hour = 0; hour < h; hour++) {
			good = dp[sleep_time][hour];
			if (good != 0) {
				new_time1 = (hour + a[sleep_time]) % h;
				new_time2 = (hour + a[sleep_time]-1) % h;
				if (l <= new_time1 and new_time1 <= r) {
					dp[sleep_time + 1][new_time1] = max(good + 1, dp[sleep_time + 1][new_time1]);
				}
				else {
					dp[sleep_time + 1][new_time1] = max(good, dp[sleep_time + 1][new_time1]);
				}
				if (l <= new_time2 and new_time2 <= r) {
					dp[sleep_time + 1][new_time2] = max(good + 1, dp[sleep_time + 1][new_time2]);
				}
				else {
					dp[sleep_time + 1][new_time2] = max(good, dp[sleep_time + 1][new_time2]);
				}
			}

		}
	}
	int ans = (*max_element(dp[n], dp[n] + h)-1);
	cout << ans;
}