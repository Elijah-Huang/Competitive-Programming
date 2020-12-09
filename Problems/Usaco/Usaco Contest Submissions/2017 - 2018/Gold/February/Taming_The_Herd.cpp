#include<bits/stdc++.h>
using namespace std;

int dp[100][100][101];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("taming.in", "r", stdin); freopen("taming.out", "w", stdout);
	int n; cin >> n;
	vector<int> logs(n);
	for (int i = 0; i < n; i++) {
		cin >> logs[i];
	}
	
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0][1] = logs[0] != 0;
	for (int loc = 0; loc < n - 1; loc++) {
		for (int last = 0; last <= loc; last++) {
			for (int used = 1; used <= last + 1; used++) {
				dp[loc + 1][last][used] = min(dp[loc + 1][last][used],
					dp[loc][last][used] + (logs[loc + 1] != (loc + 1 - last)));
				dp[loc + 1][loc + 1][used + 1] = min(dp[loc + 1][loc + 1][used + 1],
					dp[loc][last][used] + (logs[loc + 1] != 0));
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int least = 100;
		for (int last = i-1; last < n; last++) {
			least = min(least, dp[n - 1][last][i]);
		}
		cout << least << '\n';
	}
}