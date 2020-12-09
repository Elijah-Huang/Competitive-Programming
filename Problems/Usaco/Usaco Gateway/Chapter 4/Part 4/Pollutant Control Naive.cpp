/*
ID: elijahj1
TASK: milk6
LANG: C++14
*/
#include<bits/stdc++.h>
using namespace std;
// Use of adjacency matrix makes coding easier, but it takes extra memory and insignificant extra time
bool dfs(int curr, int& end, vector<int>& path, vector<vector<int>>& adj, 
	vector<int>& levels, vector<int>& visited, vector<vector<int>>& weights) {
	if (curr == end) {
		return true;
	}
	for (auto neighbor : adj[curr]) {
		if (levels[neighbor] == levels[curr] + 1 and visited[neighbor] == 0
			and weights[curr][neighbor] > 0) {
			path.push_back(neighbor);
			visited[neighbor] = 1;
			if (dfs(neighbor, end, path, adj, levels,visited,weights)) {
				return true;
			}
			path.pop_back();
		}
	}
	return false;
}
struct edge {
	int w, u, v, idx;
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("milk6.in", "r", stdin); freopen("milk6.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	vector<edge> initial_edges;
	vector<vector<int>> weights(n + 1,vector<int>(n+1));
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(v);
		adj[v].push_back(u);
		initial_edges.push_back(edge{ w,u,v,i + 1 });
		weights[u][v] += w;
	}
	vector<vector<int>> initial_weights = weights;
	sort(initial_edges.begin(), initial_edges.end(), [&](edge& a, edge& b) {return a.w > b.w; });

	// calulate max_flow

	int max_flow = 0;
	bool has_flow = true;
	while (has_flow) {
		vector<int> levels(n + 1,-1);
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
				flow_found = dfs(1, n, path, adj, levels,visited,weights);
				if (flow_found) {
					int bottleneck = 1 << 30;
					for (int i = 0; i < path.size() - 1; i++) {
						bottleneck = min(bottleneck, weights[path[i]][path[i + 1]]);
					}
					for (int i = 0; i < path.size() - 1; i++) {
						weights[path[i]][path[i + 1]] -= bottleneck;
					}
					for (int i = 0; i < path.size() - 1; i++) {
						weights[path[i+1]][path[i]] += bottleneck;
					}
					max_flow += bottleneck;
				}
			}

		}
	}

	// min_cut portion

	cout << max_flow << ' ';
	int idx = 0;
	int total_cut = 0;
	vector<int> min_cut;
	while (max_flow != total_cut) {
		bool has_flow = true;
		int max_flow2 = 0;
		while (initial_edges[idx].w > max_flow - total_cut) {
			idx++;
		}
		initial_weights[initial_edges[idx].u][initial_edges[idx].v] -= initial_edges[idx].w;
		vector<vector<int>> weights2 = initial_weights;	
		while (has_flow) {
			vector<int> levels(n + 1, -1);
			levels[1] = 0;
			queue<int> q({ 1 });
			while (!q.empty()) {
				int curr = q.front();
				q.pop();
				for (auto neighbor : adj[curr]) {
					if (weights2[curr][neighbor] > 0 and levels[neighbor] == -1) {
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
					flow_found = dfs(1, n, path, adj, levels, visited, weights2);
					if (flow_found) {
						int bottleneck = 1 << 30;
						for (int i = 0; i < path.size() - 1; i++) {
							bottleneck = min(bottleneck, weights2[path[i]][path[i + 1]]);
						}
						for (int i = 0; i < path.size() - 1; i++) {
							weights2[path[i]][path[i + 1]] -= bottleneck;
						}
						for (int i = 0; i < path.size() - 1; i++) {
							weights2[path[i + 1]][path[i]] += bottleneck;
						}
						max_flow2 += bottleneck;
					}
				}
			}
		}
		if (max_flow - total_cut - initial_edges[idx].w == max_flow2) {
			min_cut.push_back(initial_edges[idx].idx);
			total_cut += initial_edges[idx].w;
		}
		else {
			initial_weights[initial_edges[idx].u][initial_edges[idx].v] += initial_edges[idx].w;
		}
		idx++;
	}
	sort(min_cut.begin(), min_cut.end());
	cout << min_cut.size() << '\n';
	for (int i = 0; i < min_cut.size(); i++) {
		cout << min_cut[i] << '\n';
	}
}