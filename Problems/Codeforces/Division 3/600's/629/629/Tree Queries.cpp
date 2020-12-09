#include <bits/stdc++.h>
using namespace std;
int n, m, k, u, v, t = 0;
vector<int> tin, tout, parent, depth;
vector<vector<int>> adj_list(2e5 + 1);
void dfs(int const& curr, int const& par = -1, int dep = 0) {
	parent[curr] = par;
	tin[curr] = t++;
	depth[curr] = dep;
	for (auto neighbor : adj_list[curr]) {
		if (neighbor != parent[curr]) {
			dfs(neighbor, curr, dep+1);
		}
	}
	tout[curr] = t++;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	tin = tout = parent = depth = vector<int>(n + 1);
	dfs(1);
	bool worked;
	while (m--) {
		cin >> k;
		vector<int> q(k);
		for (auto& i : q) {
			cin >> i;
		}
		int lowest = q[0];
		for (auto i : q) {
			if (depth[i] > depth[lowest]) {
				lowest = i;
			}
		}
		for (int i = 0; i < k; i++) {
			if (q[i] != lowest and parent[q[i]] != -1) {
				q[i] = parent[q[i]];
			}
		}
		worked = true;
		for (auto i : q) {
			if (not (tin[i] <= tin[lowest] and tout[i] >= tout[lowest])) {
				worked = false;
				break;
			}
		}
		if (worked) cout << "YES\n";
		else cout << "NO\n";
	}
}