#include<bits/stdc++.h>
using namespace std;

int n, x;
int weights[20];
// {elevators used, min weight used in 1 available elevator} | bitmask (people in an elevator) | 
pair<int,int> dp[1 << 20];

int main() {
	cin >> n >> x;

	for (int i = 0; i < n; i++) {
		cin >> weights[i];
	}

	memset(dp, 0x3f, (1<<n)*sizeof(dp[0]));
	dp[0] = { 1,0 };
	for (int i = 0; i < 1 << n; i++) {
		for (int j = 0; j < n; j++) {
			if (((i>>j) & 1) ^ 1) {
				if (dp[i].second + weights[j] <= x) {
					dp[i + (1 << j)] = min(dp[i + (1 << j)], { dp[i].first, dp[i].second + weights[j] });
				}
				else {
					dp[i + (1 << j)] = min(dp[i + (1 << j)], { dp[i].first + 1, weights[j] });
				}
			}
		}
	}

	cout << dp[(1 << n) - 1].first;
}