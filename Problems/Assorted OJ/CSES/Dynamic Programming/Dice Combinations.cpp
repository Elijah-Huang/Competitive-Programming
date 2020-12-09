#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int dp[int(1e6 + 10)];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;

	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int roll = 1; roll <= 6; roll++) {
			dp[i + roll] = (dp[i + roll] + dp[i]) % mod;
		}
	}

	cout << dp[n];
}