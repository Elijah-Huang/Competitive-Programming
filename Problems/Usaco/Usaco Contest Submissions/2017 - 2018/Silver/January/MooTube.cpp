#include<bits/stdc++.h>
using namespace std;

struct edge {
	int v, w;
};

void dfs(int curr, int parent, vector<vector<edge>>& adj, int& total, int& k) {
	for (auto neighbor : adj[curr]) {
		if (neighbor.v == parent or neighbor.w < k) continue;
		total++;
		dfs(neighbor.v, curr, adj, total, k);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("mootube.in", "r", stdin); freopen("mootube.out", "w", stdout);
	int n, q, mink = 0;
	cin >> n >> q;
	vector<vector<edge>> adj(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		mink = min(mink, w);
		u--; v--;
		adj[u].push_back({ v,w });
		adj[v].push_back({ u,w });
	}
	for (int i = 0; i < q; i++) {
		int v, k;
		cin >> k >> v;
		if (k <= mink) {
			cout << n-1 << '\n';
		}
		else {
			v--;
			int total = 0;
			dfs(v, -1, adj, total, k);
			cout << total << '\n';
		}
	}
}