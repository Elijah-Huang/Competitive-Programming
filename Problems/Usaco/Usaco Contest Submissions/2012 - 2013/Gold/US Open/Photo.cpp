#include<bits/stdc++.h>
using namespace std;

int dp[int(2e5 + 1)];
vector<int> events[int(2e5 + 2)][2];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	freopen("photo.in", "r", stdin); freopen("photo.out", "w", stdout);
	int n, m; cin >> n >> m;
	int ans = -1;
	int furthest_start = 0;
	multiset<int, greater<int>> buildable_states;
	vector<int> mn_contained(n + 1, n + 1);
	vector<int> mx_end(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		mx_end[a] = max(mx_end[a], b + 1);
		mn_contained[a-1] = min(mn_contained[a-1], b + 1);
		furthest_start = max(furthest_start, a);
	}

	for (int i = 2; i <= n; i++) {
		mx_end[i] = max(mx_end[i], mx_end[i - 1]);
	}
	for (int i = n-1; i >= 0; i--) {
		mn_contained[i] = min(mn_contained[i], mn_contained[i + 1]);
	}

	memset(dp, 0xff, sizeof(dp));
	dp[0] = 0;
	buildable_states.insert(0);
	events[mn_contained[0]][1].push_back(0);
	for (int i = 1; i <= n; i++) {
		for (auto& e : events[i][0]) {
			buildable_states.insert(e);
		}
		for (auto& e : events[i][1]) {
			buildable_states.erase(buildable_states.find(e));
		}

		if (!buildable_states.empty()) {
			dp[i] = 1 + *buildable_states.begin();
		}
		
		if (dp[i] != -1 and mn_contained[i] > mx_end[i]) {
			if (mx_end[i] <= i) {
				buildable_states.insert(dp[i]);
			}
			else {
				events[mx_end[i]][0].push_back(dp[i]);
			}
			events[mn_contained[i]][1].push_back(dp[i]);
		}
	}

	for (int i = furthest_start; i <= n; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans;
}