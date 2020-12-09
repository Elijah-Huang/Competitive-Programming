#include<bits/stdc++.h>
using namespace std;

int n, k;
int t = 0;
int dist[int(1e5)];
int tin[int(1e5)], tout[int(1e5)];
vector<int> leaves;
vector<vector<int>> adj(1e5);

void dfs(int curr, int parent) {
	if (curr == k) {
		dist[curr] = 0;
	}
	else {
		dist[curr] = dist[parent] + 1;
	}

	tin[curr] = t++;
	if (adj[curr].size() == 1) {
		leaves.push_back(curr);
	}
	for (auto neighbor : adj[curr]) {
		if (neighbor == parent) continue;
		dfs(neighbor, curr);
	}
	tout[curr] = t++;
}

bool in_subtree(int root, int node) {
	return tin[node] >= tin[root] and tout[node] <= tout[root];
}

int new_bound(int root, int l) {
	while (l < leaves.size() and in_subtree(root, leaves[l])) {
		l++;
	}
	return l;
}

int solve(int curr, int parent, int l) {
	if (adj[curr].size() == 1) {
		return 1;
	}
	else if (adj[curr].size() == 2 and curr != k) {
		for (auto neighbor : adj[curr]) {
			if (neighbor != parent) {
				return solve(neighbor, curr, l);
			}
		}
	}
	else {
		int least = 1e5;
		int r = new_bound(curr, l);
		for (int i = l; i < r; i++) {
			least = min(least, dist[leaves[i]] - dist[curr]);
		}
		if (least <= dist[curr]) {
			return 1;
		}
		else {
			int amt = 0, l2 = l;
			for (auto neighbor : adj[curr]) {
				if (neighbor != parent) {
					amt += solve(neighbor, curr, l2);
					l2 = new_bound(neighbor, l2);
				}
			}
			return amt;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("atlarge.in", "r", stdin); freopen("atlarge.out", "w", stdout);
	cin >> n >> k; k--;
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(k, -1);
	cout << solve(k,-1,0);
}