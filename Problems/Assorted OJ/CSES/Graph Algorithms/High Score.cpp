#include<bits/stdc++.h>
using namespace std;

struct edge {
	int v, w;
};

vector<bool> in_neg_cycle;
vector<vector<vector<edge>>> adj;
vector<long long> dist;
vector<vector<bool>> visited;
vector<vector<bool>> touched_neg_cycle;

void dfs_comp(int source, vector<bool>& visited, vector<vector<edge>>& adj,
	vector<bool>& touched_neg_cycle) {
	stack<int> s; s.push(source);
	while (!s.empty()) {
		int curr = s.top();
		if (!visited[curr]) {
			visited[curr] = 1;
			if (in_neg_cycle[curr]) {
				touched_neg_cycle[curr] = 1;
			}
			for (auto neighbor : adj[curr]) {
				s.push(neighbor.v);
			}
		}
		else {
			s.pop();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	dist.resize(n + 1, 1ll << 62);
	dist[1] = 0;
	adj.resize(2, vector<vector<edge>>(n+1));
	for (int i = 0; i < m; i++) {
		int a, b, w; cin >> a >> b >> w;
		adj[0][a].push_back({ b, -w });
		adj[1][b].push_back({ a, -w });
	}

	in_neg_cycle.resize(n + 1);
	bool neg_cycle = 0;
	bool relaxed = 1;
	int iterations = 0;
	while (relaxed) {
		relaxed = 0;

		for (int i = 1; i <= n; i++) {
			for (auto& edge : adj[0][i]) {
				if (dist[edge.v] > dist[i] + edge.w) {
					dist[edge.v] = dist[i] + edge.w;
					relaxed = 1;
					if (iterations == n - 1) {
						in_neg_cycle[edge.v] = 1;
					}
				}
			}
		}

		iterations++;
		if (iterations == n and relaxed) {
			neg_cycle = 1;
			break;
		}
	}

	if (neg_cycle) {
		visited = vector<vector<bool>>(2, vector<bool>(n + 1));
		touched_neg_cycle = vector<vector<bool>>(2, vector<bool>(n + 1));
		dfs_comp(1, visited[0], adj[0], touched_neg_cycle[0]);
		dfs_comp(n, visited[1], adj[1], touched_neg_cycle[1]);
		for (int i = 1; i <= n; i++) {
			if (touched_neg_cycle[0][i] == 1 and touched_neg_cycle[1][i] == 1) {
				cout << -1;
				return 0;
			}
		}
		cout << -dist[n];
	}
	else {
		cout << -dist[n];
	}
}