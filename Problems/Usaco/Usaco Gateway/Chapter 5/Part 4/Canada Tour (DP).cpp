/*
ID: elijahj1
TASK: tour
LANG: C++14
*/
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("tour.in", "r", stdin); freopen("tour.out", "w", stdout);
	int n, ve, mx = 1;
	cin >> n >> ve;
	unordered_map<string, int> name_to_num;
	vector<vector<bool>> adj(n, vector<bool>(n));
	vector<vector<int>> dp(n, vector<int>(n));
	dp[0][0] = 1;
	int start = 0, end = n - 1;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		name_to_num[s] = i;
	}
	for (int i = 0; i < ve; i++) {
		string u, v;
		cin >> u >> v;
		if (name_to_num[u] < name_to_num[v]) {
			adj[name_to_num[u]][name_to_num[v]] = 1;
		}
		else {
			adj[name_to_num[v]][name_to_num[u]] = 1;
		}
	}
	for (int start = 0; start < n; start++) {
		for (int new_end = start + 1; new_end < n; new_end++) {
			for (int old_end = 0; old_end < new_end; old_end++) {
				if (dp[start][old_end] and adj[old_end][new_end]) {
					dp[start][new_end] = max(dp[start][new_end], dp[start][old_end] + 1);
					dp[new_end][start] = dp[start][new_end];
				}
			}
		}
	}
	for (int start = 0; start < n-1; start++) {
		if (adj[start][n - 1]) {
			mx = max(mx, dp[start][n - 1]);
		}
	}
	cout << mx << '\n';
}