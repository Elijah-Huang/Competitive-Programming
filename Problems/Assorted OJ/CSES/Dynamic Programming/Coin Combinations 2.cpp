#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int dp[int(1e6 + 1)];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	int x; cin >> x;
	vector<int> coins(n);
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	dp[0] = 1;
	for (auto c : coins) {
		for (int i = 0; i < x; i++) {
			if (i + c <= x) {
				dp[i + c] = (dp[i+c] + dp[i]) % mod;
			}
		}
	}

	cout << dp[x];
}