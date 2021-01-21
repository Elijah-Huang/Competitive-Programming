#include<bits/stdc++.h>
using namespace std;

struct event {
	int sz;
	bool t;
};

const int maxn = 3001, mod = 1e9 + 7;
int n;
// dp[number of unmatched cows][1 if a cow has been excluded from the matching else 0]
long long dp[maxn][2];
event events[2 * maxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> events[i].sz;
		events[i].t = 1;
	}
	for (int i = n; i < 2 * n; i++) {
		cin >> events[i].sz;
		events[i].t = 0;
	}

	sort(events, events + 2 * n, [&](const event& a, const event& b) {if (a.sz == b.sz) return a.t > b.t; return a.sz < b.sz; });

	dp[0][0] = 1;
	for (int i = 0; i < 2 * n; i++) {
		if (events[i].t) {
			// cow
			for (int j = n-1; j >= 0; j--) {
				// add cow
				dp[j + 1][0] = (dp[j + 1][0] + dp[j][0]) % mod;
				dp[j + 1][1] = (dp[j + 1][1] + dp[j][1]) % mod;
				// don't add cow
				dp[j][1] = (dp[j][1] + dp[j][0]) % mod;
				dp[j][0] = 0;
				// if don't add cow no transition from dp[j][1]
			}
		}
		else {
			// barn
			for (int j = 0; j <= n; j++) {
				//add barn
				if (j) {
					dp[j - 1][0] = (dp[j - 1][0] + j * dp[j][0]) % mod;
					dp[j - 1][1] = (dp[j - 1][1] + j * dp[j][1]) % mod;
				}
				// barn is unmatched and 2nd state = 1 invalidates pairings in dp[j][1]
				dp[j][1] = 0;
				// if don't match barn no transition from dp[j][0]
			}
		}
	}

	cout << (dp[0][0] + dp[0][1]) % mod;
}