/*
ID: elijahj1
TASK: milk6
LANG: C++14
*/
#include<bits/stdc++.h>
using namespace std;
// Use of adjacency matrix makes coding easier, but it takes extra memory and insignificant extra time
bool dfs(int curr, int& end, vector<int>& path, vector<vector<int>>& adj,
	vector<int>& levels, vector<int>& visited, vector<vector<long long>>& weights) {
	if (curr == end) {
		return true;
	}
	for (auto neighbor : adj[curr]) {
		if (levels[neighbor] == levels[curr] + 1 and visited[neighbor] == 0
			and weights[curr][neighbor] > 0) {
			path.push_back(neighbor);
			visited[neighbor] = 1;
			if (dfs(neighbor, end, path, adj, levels, visited, weights)) {
				return true;
			}
			path.pop_back();
		}
	}
	return false;
}
void dfs(int curr, vector<vector<int>>& adj, vector<vector<long long>>& weights, vector<int>& visited) {
	visited[curr] = 1;
	for (auto neighbor : adj[curr]) {
		if (visited[neighbor] == 0 and weights[curr][neighbor] > 0) {
			dfs(neighbor, adj, weights, visited);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("milk6.in", "r", stdin); freopen("milk6.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	vector<vector<long long>> weights(n + 1, vector<long long>(n + 1));
	vector<vector<int>> original(n + 1, vector<int>(n + 1));
	vector<vector<vector<int>>> idx(n + 1, vector<vector<int>>(n + 1));
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		if (weights[u][v] == 0 and weights[v][u] == 0) {
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		weights[u][v] += 1001*w + 1;
		original[u][v] = 1;
		idx[u][v].push_back(i + 1);
	}

	// calulate max_flow

	long long max_flow = 0;
	bool has_flow = true;
	while (has_flow) {
		vector<int> levels(n + 1, -1);
		levels[1] = 0;
		queue<int> q({ 1 });
		while (!q.empty()) {
			int curr = q.front();
			q.pop();
			for (auto neighbor : adj[curr]) {
				if (weights[curr][neighbor] > 0 and levels[neighbor] == -1) {
					levels[neighbor] = levels[curr] + 1;
					q.push(neighbor);
				}
			}
		}
		if (levels[n] == -1) {
			has_flow = false;
		}
		else {
			vector<int> visited(n + 1);
			bool flow_found = true;
			while (flow_found) {
				vector<int> path = { 1 };
				flow_found = dfs(1, n, path, adj, levels, visited, weights);
				if (flow_found) {
					long long bottleneck = 1ll << 62;
					for (int i = 0; i < path.size() - 1; i++) {
						bottleneck = min(bottleneck, weights[path[i]][path[i + 1]]);
					}
					for (int i = 0; i < path.size() - 1; i++) {
						weights[path[i]][path[i + 1]] -= bottleneck;
					}
					for (int i = 0; i < path.size() - 1; i++) {
						weights[path[i + 1]][path[i]] += bottleneck;
					}
					max_flow += bottleneck;
				}
			}

		}
	}

	// min_cut portion

	cout << max_flow/1001 << ' ';
	vector<int> min_cut;
	vector<int> visited(n + 1);
	dfs(1, adj, weights, visited);
	for (int node = 1; node <= n; node++) {
		if (visited[node]) {
			for (auto neighbor : adj[node]) {
				if (visited[neighbor] == 0 and original[node][neighbor]) {
					for (auto i : idx[node][neighbor]) {
						min_cut.push_back(i);
					}
				}
			}
		}
	}
	sort(min_cut.begin(), min_cut.end());
	cout << min_cut.size() << '\n';
	for (int i = 0; i < min_cut.size(); i++) {
		cout << min_cut[i] << '\n';
	}
}