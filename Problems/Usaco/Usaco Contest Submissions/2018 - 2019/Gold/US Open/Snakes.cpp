#include<bits/stdc++.h>
using namespace std;

int dp[401][402];
int sizes[400];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("snakes.in", "r", stdin); freopen("snakes.out", "w", stdout);
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> sizes[i];
	}

	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	for (int loc = 0; loc < n; loc++) {
		for (int switched = 0; switched <= k; switched++) {
			int curr_mx = 0;
			int curr_tot = 0;
			for (int new_loc = loc + 1; new_loc <= n; new_loc++) {
				curr_tot += sizes[new_loc-1];
				curr_mx = max(curr_mx, sizes[new_loc-1]);
				dp[new_loc][switched + 1] = min(dp[new_loc][switched + 1], 
					dp[loc][switched] + curr_mx * (new_loc - loc) - curr_tot);
			}
		}
	}

	cout << dp[n][k + 1];
}