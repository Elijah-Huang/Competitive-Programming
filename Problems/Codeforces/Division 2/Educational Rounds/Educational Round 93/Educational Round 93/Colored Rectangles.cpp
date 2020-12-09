#include<bits/stdc++.h>
using namespace std;

int dp[201][201][201]{};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int r, g, b;
	cin >> r >> g >> b;
	vector<int> R = { 0 };
	vector<int> G = { 0 };
	vector<int> B = { 0 };
	for (int i = 0; i < r; i++) {
		int a; cin >> a;
		R.push_back(a);
	}
	for (int i = 0; i < g; i++) {
		int a; cin >> a;
		G.push_back(a);
	}
	for (int i = 0; i < b; i++) {
		int a; cin >> a;
		B.push_back(a);
	}

	sort(R.begin(), R.end());
	sort(B.begin(), B.end());
	sort(G.begin(), G.end());

	dp[r][g][b] = 1;

	int ans = 0;
	for (int r1 = 200; r1 >= 0; r1--) {
		for (int g1 = 200; g1 >= 0; g1--) {
			for (int b1 = 200; b1 >= 0; b1--) {

				ans = max(ans, dp[r1][g1][b1]);

				if (dp[r1][g1][b1]) {
					if (r1 > 0 and g1 > 0) {
						dp[r1 - 1][g1 - 1][b1] = max(dp[r1 - 1][g1 - 1][b1],
							dp[r1][g1][b1] + R[r1] * G[g1]);
					}
					if (r1 > 0 and b1 > 0) {
						dp[r1 - 1][g1][b1-1] = max(dp[r1 - 1][g1][b1-1],
							dp[r1][g1][b1] + R[r1] * B[b1]);
					}
					if (b1 > 0 and g1 > 0) {
						dp[r1][g1 - 1][b1 - 1] = max(dp[r1][g1 - 1][b1 - 1],
							dp[r1][g1][b1] + B[b1] * G[g1]);
					}
				}

			}
		}
	}

	cout << ans - 1;
}