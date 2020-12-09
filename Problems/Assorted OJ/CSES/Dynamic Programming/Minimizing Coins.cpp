#include<bits/stdc++.h>
using namespace std;

int dp[int(1e6 + 1)];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	int x; cin >> x;
	vector<int> coins(n);
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for (auto c : coins) {
		for (int i = 0; i < x; i++) {
			if (i + c <= x and dp[i+c] > dp[i] + 1) {
				dp[i + c] = dp[i] + 1;
			}
		}
	}
	
	if (dp[x] > 1e6) {
		dp[x] = -1;
	}
	cout << dp[x];
}