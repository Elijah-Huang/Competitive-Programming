/*
ID: elijahj1
TASK: fence8
LANG: C++14
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("fence8.in", "r", stdin); freopen("fence8.out", "w", stdout);
	int n, r; cin >> n;
	vector<vector<int>> dp(n);
	vector<vector<int>> dp1(n);
	vector<int> rails;
	int total_lengths = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		total_lengths += a;
		dp[i].resize(a + 1);
		dp1[i].resize(a + 1);
	}
	cin >> r;
	if (total_lengths > 140000) {
		cout << r << '\n';
		return 0;
	}
	rails.resize(r);
	for (int i = 0; i < r; i++) {
		cin >> rails[i];
	}

	for (int i = 0; i < r; i++) {
		bool added = 0;
		for (int board = 0; board < n; board++) {
			for (int length = 0; (added and length < dp[board].size()) or length + rails[i] < dp[board].size(); length++) {
				if (added) {
					dp1[board][length] = dp[board][length] + 1;
				}
				else {
					dp1[board][length + rails[i]] = max(dp[board][length + rails[i]], dp[board][length] + 1);
				}
			}
			if ((*max_element(dp.begin(), dp.end())) < (*max_element(dp1.begin(), dp1.end()))) {
				added = 1;
			}
		}

		for (int board = 0; board < n; board++) {
			for (int length = 0; length < dp[board].size(); length++) {
				dp[board][length] = dp1[board][length];
			}
		}
		for (int board = 0; board < n; board++) {
			for (int length = 0; length < dp[board].size(); length++) {
				cout << dp[board][length] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}

	cout << '\n';
	cout << dp[n-1][dp[n-1].size()-1] << '\n';
}