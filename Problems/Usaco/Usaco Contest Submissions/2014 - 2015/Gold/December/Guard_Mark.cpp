// O(n*2^n)
#include<bits/stdc++.h>
using namespace std;

struct cow {
	long long h, w, s;
};

const int maxn = 20;
int n, h;
cow cows[maxn];
// dp[i] -> maximum safety factor for set of cows represented by bitmask for i
long long dp[1 << maxn];
long long ans = 0;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("guard.in", "r", stdin); freopen("guard.out", "w", stdout);

	cin >> n >> h;

	for (int i = 0; i < n; i++) {
		cin >> cows[i].h >> cows[i].w >> cows[i].s;
	}

	dp[0] = 1ll << 62;
	for (int i = 1; i < (1 << n); i++) {
		long long tot_height = 0;

		for (int j = 0; j < n; j++) {
			// transition is making cow j the top cow 
			// bottom cows are previously calcuated set of cows with max safety factor
			if ((i >> j) & 1) {
				tot_height += cows[j].h;

				if (cows[j].w <= dp[i-(1<<j)]) {
					dp[i] = max(dp[i], min(cows[j].s, dp[i - (1<<j)] - cows[j].w));
				}
			}
		}

		if (tot_height >= h) {
			ans = max(ans, dp[i]);
		}
	}
	
	if (ans == 0) {
		cout << "Mark is too tall\n";
	}
	else {
		cout << ans;
	}
}