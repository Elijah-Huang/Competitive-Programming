#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;
int n, m;
// 0 -> normal 1 -> transposed | compressed -> graph where scc's are nodes
vector<int> adj[2][maxn], compressed_adj[2][maxn];
bool visited[maxn]; // for topological sort
stack<int> s;
// sccs[i] -> nodes in ith scc
vector<vector<int>> sccs(1);
int node_to_scc[maxn];

void dfs_top(int c) {
	visited[c] = 1;

	for (auto n : adj[0][c]) {
		if (!visited[n]) {
			dfs_top(n);
		}
	}

	s.push(c);
}

void dfs_scc(int c) {
	node_to_scc[c] = sccs.size() - 1;
	sccs.back().push_back(c);

	for (auto n : adj[1][c]) {
		if (!node_to_scc[n]) {
			dfs_scc(n);
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m;

	// set up adj list
	while (m--) {
		int a, b; cin >> a >> b;
		adj[0][a].push_back(b);
		adj[1][b].push_back(a);
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
		for (int j = 0; j < 2; j++) {
			for (auto ne : adj[j][i]) {
				if (node_to_scc[i] != node_to_scc[ne]) {
					compressed_adj[j][node_to_scc[i]].push_back(node_to_scc[ne]);
				}
			}
		}
	}
}