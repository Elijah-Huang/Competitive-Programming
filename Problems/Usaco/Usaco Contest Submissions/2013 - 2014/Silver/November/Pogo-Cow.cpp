#include <bits/stdc++.h>
using namespace std;

struct target {
	int x, p;
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	freopen("pogocow.in", "r", stdin); freopen("pogocow.out", "w", stdout);
	int dp[1000][1000];
	int n; cin >> n;
	vector<target> targets(n);
	for (int i = 0; i < n; i++) {
		int x, p;
		cin >> x >> p;
		targets[i] = { x,p };
	}
	sort(targets.begin(), targets.end(),
		[&](const target& a, const target& b) {return a.x < b.x; });
	for (int i = 0; i < n; i++) {
		dp[i][i] = targets[i].p;
	}
	for (int end = 0; end < n; end++) {
		for (int last = end - 1; last >= 0; last--) {
			int last2 = last;
			while (last2 >= 0 and targets[end].x - targets[last].x >= targets[last].x - targets[last2].x) {
				dp[end][last] = max(dp[end][last], targets[end].p + dp[last][last2]);
				last2--;
			}
		}
	}
	for (int end = n-1; end >= 0; end--) {
		for (int last = end + 1; last < n; last++) {
			int last2 = last;
			while (last2 < n and targets[last].x - targets[end].x >= 
				targets[last2].x - targets[last].x) {
				dp[end][last] = max(dp[end][last], targets[end].p + dp[last][last2]);
				last2++;
			}
		}
	}
	
	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mx = max(mx, dp[i][j]);
		}
	}

	cout << mx;
}