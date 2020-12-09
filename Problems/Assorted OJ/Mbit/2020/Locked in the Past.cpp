#include<bits/stdc++.h>
using namespace std;

long long dp[1001];
int values[2][1001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> values[0][i];
		values[1][i] = k + 1 - values[0][i];
	}

	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		vector<long long> costs = { 0,0 };
		for (int j = i + 1; j <= n; j++) {
			for (int k = 0; k < 2; k++) {
				if (j > i + 1) {
					costs[k] -= values[k][j - 1];
					costs[k] += abs(values[k][j] - values[k][j - 1]) + values[k][j];
				}
				else {
					costs[k] = 2 * values[k][j];
				}
			}

			dp[j] = min(dp[j], dp[i] + min(costs[0], costs[1])/2);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << dp[i] << ' ';
	}
	//cout << dp[n];
}