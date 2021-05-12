#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 1;
int n, m, start;
// 0 -> normal 1 -> transposed | compressed -> graph where scc's are nodes
vector<pair<int,long long>> adj[2][maxn], compressed_adj[2][maxn];
bool visited[maxn]; // for topological sort
stack<int> s;
// sccs[i] -> nodes in ith scc
vector<vector<int>> sccs(1);
int node_to_scc[maxn];

void dfs_top(int c) {
	visited[c] = 1;

	for (auto [n,w] : adj[0][c]) {
		if (!visited[n]) {
			dfs_top(n);
		}
	}

	s.push(c);
}

void dfs_scc(int c) {
	node_to_scc[c] = sccs.size() - 1;
	sccs.back().push_back(c);

	for (auto [n,w] : adj[1][c]) {
		if (!node_to_scc[n]) {
			dfs_scc(n);
		}
	}
}

long long tot_shroom(int w) {
	int l = 0, r = 3e4;
	while (l != r) {
		int m = (l + r + 1) / 2;

		if (m * (m + 1) / 2 <= w) {
			l = m;
		}
		else {
			r = m - 1;
		}
	}

	long long n = l;
	
	return (n + 1) * w - (n * (n + 1) / 2 + n * (n + 1) * (2 * n + 1) / 6) / 2;
}

long long shrooms[maxn];
long long dp[maxn];
bool vis[maxn];

void dfs_dp(int i) {
	long long mx = 0;

	vis[i] = 1;

	for (auto [ne,w] : compressed_adj[0][i]) {
		if (!vis[ne]) {
			dfs_dp(ne);
		}
		mx = max(mx, dp[ne] + w);
	}

	dp[i] = mx + shrooms[i];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m;

	// set up adj list
	while (m--) {
		int a, b, w; cin >> a >> b >> w;
		adj[0][a].push_back({ b, w });
		adj[1][b].push_back({ a, w });
	}

	// topological sort
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs_top(i);
		}
	}

	// find sccs
	while (!s.empty()) {
		if (!node_to_scc[s.top()]) {
			sccs.resize(sccs.size() + 1);
			dfs_scc(s.top());
		}

		s.pop();
	}

	// compress graph
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 1; j++) {
			for (auto [n,w]: adj[j][i]) {
				if (node_to_scc[i] != node_to_scc[n]) {
					compressed_adj[j][node_to_scc[i]].push_back({ node_to_scc[n], w });
				}
				else {
					shrooms[node_to_scc[i]] += tot_shroom(w);
				}
			}
		}
	}

	cin >> start;

	dfs_dp(node_to_scc[start]);

	cout << dp[node_to_scc[start]] << '\n';
}