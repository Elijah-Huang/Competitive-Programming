#include<bits/stdc++.h>
using namespace std;

int dp[16][16];
int grid[15][15];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("partition.in", "r", stdin); freopen("partition.out", "w", stdout);
	int min_max_size = 1e6;
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < 1 << (n - 1); i++) {
		vector<int> fences;
		for (int j = 0; j < (n - 1); j++) {
			if (1<<j & i) {
				fences.push_back(j);
			}
		}
		fences.push_back(n - 1);

		if (fences.size() - 1 > k or k -(fences.size()-1) > n-1) {
			continue;
		}
		
		memset(dp, 0x3f, sizeof(dp));
		dp[0][0] = 0;
		for (int old_end = 0; old_end < n; old_end++) {
			vector<int> added_sizes(fences.size());
			for (int new_end = old_end + 1; new_end <= n; new_end++) {
				int start = 0;
				for (int j = 0; j < fences.size(); j++) {
					for (int i = start; i <= fences[j]; i++) {
						added_sizes[j] += grid[i][new_end-1];
					}
					start = fences[j] + 1;
				}
				int max_added = *max_element(added_sizes.begin(), added_sizes.end());

				for (int fences_used = 0; fences_used <= k-(fences.size()-1); fences_used++) {
					dp[new_end][fences_used + 1] = min(dp[new_end][fences_used + 1], max(dp[old_end][fences_used], max_added));
				}
			}
		}

		min_max_size = min(min_max_size, dp[n][k-(fences.size()-1) + 1]);
	}

	cout << min_max_size << '\n';
}