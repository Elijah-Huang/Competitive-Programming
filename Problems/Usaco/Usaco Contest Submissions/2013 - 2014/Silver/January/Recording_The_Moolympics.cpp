#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("recording.in", "r", stdin); freopen("recording.out", "w", stdout);
	int n; cin >> n;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	vector<pair<int, int>> programs(n);
	for (int i = 0; i < n; i++) {
		cin >> programs[i].first;
		cin >> programs[i].second;
	}
	sort(programs.begin(), programs.end());

	vector<vector<int>> dp(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			dp[i][j] = 2;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int f = i, s = j;
			if (programs[i].second > programs[j].second) {
				swap(f, s);
			}
			for (int j2 = j + 1; j2 < n; j2++) {
				if (programs[j2].first >= programs[f].second) {
					dp[s][j2] = max(dp[s][j2],dp[i][j] + 1);
				}
			}
		}
	}

	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mx = max(mx, dp[i][j]);
		}
	}

	cout << mx;
}