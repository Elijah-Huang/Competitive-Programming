#include<bits/stdc++.h>
using namespace std;

int dp[250001], dp2[250001];

struct cow {
	int w, t;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("talent.in","r",stdin); freopen("talent.out","w",stdout);
	double best_ratio = 0;
	int n, w; cin >> n >> w;
	vector<cow> cows(n);
	for (int i = 0; i < n; i++) {
		cin >> cows[i].w >> cows[i].t;
	}

	memset(dp, 0x3f, sizeof(dp));
	memset(dp2, 0x3f, sizeof(dp2));
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int t = 0; t + cows[i].t <= 250000; t++) {
			dp2[t + cows[i].t] = min(dp2[t + cows[i].t], dp[t] + cows[i].w);
		}
		for (int t = 0; t <= 250000; t++) {
			dp[t] = min(dp[t], dp2[t]);
		}
	}

	for (int t = 0; t <= 250000; t++) {
		if (dp[t] >= w) {
			best_ratio = max(best_ratio, double(t) / dp[t]);
		}
	}
	best_ratio *= 1000;

	if (fabs(round(best_ratio) - best_ratio) < 1e-8) {
		cout << int(round(best_ratio)) << '\n';
	}
	else {
		cout << int(best_ratio) << '\n';
	}
}