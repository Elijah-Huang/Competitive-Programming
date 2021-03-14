#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;	
int n, m;
// adj[0] -> normal adj[1] -> transposed | compressed -> graph where scc's are nodes
vector<int> adj[2][maxn], compressed_adj[2][maxn];
bool visited[maxn]; // for topological sort
vector<int> s;
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

	s.push_back(c);
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

// dp on DAG
// 0 -> max dist from i to node_to_scc[1], 1 -> max dist from node_to_scc[1] to i
int distinct[2][maxn];
bool tried[2][maxn];
void dfs(int c, int j) {
	for (auto n : compressed_adj[j][c]) {
		// don't want to add the same nodes in component c to distinct[j][c]
		if (n == c) {
			continue;
		}

		// make sure you don't visit multiple times via tried 
		// (since val of distinct might = 0 even after dfs)
		if (distinct[j][n] == 0 and !tried[j][n]) {
			dfs(n, j);
			tried[j][n] = 1;
		}

		// if == 0 then that means no path reaches 1, so can't build off of it
		if (distinct[j][n] > 0) {
			distinct[j][c] = max(distinct[j][c], int(distinct[j][n] + sccs[c].size()));
		}
	}
}

int ans = 0;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("grass.in", "r", stdin); freopen("grass.out", "w", stdout);

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
		if (!node_to_scc[s.back()]) {
			sccs.resize(sccs.size() + 1);
			dfs_scc(s.back());
		}

		s.pop_back();
	}

	// create compressed graph
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			for (auto n : adj[j][i]) {
				compressed_adj[j][node_to_scc[i]].push_back(node_to_scc[n]);
			}
		}
	}
	

	// dp on DAG with memoization
	for (int j = 0; j < 2; j++) {
		// base case
		distinct[j][node_to_scc[1]] = sccs[node_to_scc[1]].size();

		for (int i = 1; i < sccs.size(); i++) {
			if (distinct[j][i] == 0) {
				dfs(i, j);
			}
		}
	}

	ans = sccs[node_to_scc[1]].size();
	for (int i = 1; i <= n; i++) {
		for (auto n : adj[1][i]) {
			int a = node_to_scc[i], b = node_to_scc[n];

			// paths from a to 1 and 1 to b cannot intersect due to scc graph being DAG
			if (a != b and distinct[1][a] != 0 and distinct[0][b] != 0) {
				ans = max(ans, int(distinct[1][a] + distinct[0][b] - sccs[node_to_scc[1]].size()));
			}
		}
	}	

	cout << ans;
}