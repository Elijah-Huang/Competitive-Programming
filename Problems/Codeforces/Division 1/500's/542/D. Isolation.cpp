#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1, mod = 998244353, b_sz = 200;

int n, k;
int last_occ[maxn], prev_occ[maxn];

int delta[maxn];
int dp[maxn];
int tot_delta[501], psums[501][2 * b_sz + 1];

void update(int i) {
	vector<int> blocks = { i / b_sz };
	if (i % b_sz == 0 and i) {
		blocks.push_back(i / b_sz - 1); // since dp[i-1] not included in psums when transitioning to new block
	}
	
	delta[i] = 1;
	if (prev_occ[i]) {
		blocks.push_back(prev_occ[i] / b_sz);
		delta[prev_occ[i]] = -1;
	}
	if (prev_occ[prev_occ[i]]) {
		blocks.push_back(prev_occ[prev_occ[i]] / b_sz);
		delta[prev_occ[prev_occ[i]]] = 0;
	}

	sort(blocks.begin(), blocks.end());
	blocks.resize(unique(blocks.begin(), blocks.end()) - blocks.begin());

	for (auto block : blocks) {
		memset(psums[block], 0, sizeof(psums[block]));
		int curr_unique = 0;

		for (int j = min(i, (block + 1) * b_sz - 1); j >= block * b_sz; j--) {
			psums[block][curr_unique + b_sz] = (psums[block][curr_unique + b_sz] + dp[j]) % mod;
			curr_unique += delta[j];
		}
		for (int j = 1; j <= 2 * b_sz; j++) {
			psums[block][j] = (psums[block][j] + psums[block][j-1]) % mod;
		}

		tot_delta[block] = curr_unique;
	}
}

void solve(int i) {
	int curr_unique = 0;

	for (int block = i / b_sz; block >= 0; block--) {
		if (k - curr_unique >= -b_sz) {
			dp[i] = (dp[i] + psums[block][min(b_sz, k - curr_unique) + b_sz]) % mod;
		}
		curr_unique += tot_delta[block];
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		int a; cin >> a;

		prev_occ[i] = last_occ[a];
		last_occ[a] = i; 
	}

	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		update(i);
		solve(i);
	}

	cout << dp[n];
}