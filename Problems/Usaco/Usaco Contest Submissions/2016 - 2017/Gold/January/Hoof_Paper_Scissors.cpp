#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int dp[(int)1e5 + 1][21][3];

bool win(int play, int play2) {
	return (play - play2 + 3) % 3 == 1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("hps.in", "r", stdin); freopen("hps.out", "w", stdout);
	int n, k; cin >> n >> k;
	vector<int> gestures;
	for (int i = 0; i < n; i++) {
		char a; cin >> a;
		switch (a) {
		case 'H':
			gestures.push_back(0);
			break;
		case 'P':
			gestures.push_back(1);
			break;
		case 'S':
			gestures.push_back(2);
			break;
		}
	}

	int best = 0;
	for (int i = 1; i <= n; i++) {
		for (int switched = 0; switched <= k; switched++) {
			for (int curr = 0; curr <= 2; curr++) {
				dp[i][switched][curr] = dp[i - 1][switched][curr] + win(curr, gestures[i-1]);
				if (!switched) {
					best = max(best, dp[i][switched][curr]);
					continue;
				}
				for (int prev_curr = 0; prev_curr <= 2; prev_curr++) {
					if (prev_curr != curr) {
						dp[i][switched][curr] = max(dp[i][switched][curr], dp[i - 1][switched - 1][prev_curr] + win(curr, gestures[i-1]));
					}
				}
				best = max(best, dp[i][switched][curr]);
			}
		}
	}

	cout << best << '\n';
}