#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("mooomoo.in", "r", stdin); freopen("mooomoo.out", "w", stdout);
	int n, b; cin >> n >> b;
	vector<int> tot_fields(n);
	vector<int> fields(n);
	vector<int> volumes(b);
	for (int i = 0; i < b; i++) {
		cin >> volumes[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> tot_fields[i];
	}

	fields[0] = tot_fields[0];
	for (int i = 1; i < n; i++) {
		fields[i] = tot_fields[i] - (max(tot_fields[i - 1] - 1,0));
	}

	int total_cows = 0;
	int most = 1e9;
	for (int i = 0; i < n; i++) {
		vector<int> dp(fields[i] + 1, most);
		dp[0] = 0;
		for (int breed = 0; breed < b; breed++) {
			for (int volume = 0; volume <= fields[i] - volumes[breed]; volume++) {
				if (dp[volume] != most) {
					dp[volume + volumes[breed]] = min(dp[volume + volumes[breed]], dp[volume] + 1);
				}
			}
		}
		if (dp[fields[i]] == -1) {
			cout << -1;
			return 0;
		}
		else {
			total_cows += dp[fields[i]];
		}
	}

	cout << total_cows;
}