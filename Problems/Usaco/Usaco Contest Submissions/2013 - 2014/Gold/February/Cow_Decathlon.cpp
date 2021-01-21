#include<bits/stdc++.h>
using namespace std;

const int maxn = 20;
int n, b;
int cows[maxn][maxn];
vector<pair<int, int>> bonuses[maxn];
int dp[1 << maxn];
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("dec.in", "r", stdin); freopen("dec.out", "w", stdout);

	cin >> n >> b;

	for (int i = 0; i < b; i++) {
		int k; cin >> k; k--;
		pair<int, int> bonus;
		cin >> bonus.first >> bonus.second;
		bonuses[k].push_back(bonus);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cows[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		sort(bonuses[i].begin(), bonuses[i].end());
	}

	for (int i = 0; i < 1 << n; i++) {
		int cows_used = 0;
		for (int j = 0; j < n; j++) {
			cows_used += ((i >> j) & 1);
		}

		for (int j = 0; j < n; j++) {
			if (((i >> j) & 1)^1) {
				int total_points = dp[i] + cows[j][cows_used];
				for (auto bonus : bonuses[cows_used]) {
					if (total_points >= bonus.first) {
						total_points += bonus.second;
					}
					else {
						break;
					}
				}

				dp[i + (1 << j)] = max(dp[i + (1 << j)], total_points);
			}
		}
	}

	cout << dp[(1 << n) - 1];
}