/*
ID: elijahj1
TASK: telecow
LANG: C++14
*/
#include<bits/stdc++.h>
using namespace std;

int s, t;
const int maxn = 100;
vector<vector<int>> adj(2*maxn + 1);
vector<vector<long long>> weights(2*maxn + 1, vector<long long>(2*maxn + 1));
vector<vector<long long>> original_weights(2*maxn + 1, vector<long long>(2*maxn + 1));
vector<int> visited(2*maxn + 1);
vector<int> levels(2*maxn + 1);
vector<int> path;

//pushing flow
bool dfs(int curr) {
	if (curr == t) {
		return true;
	}
	for (auto neighbor : adj[curr]) {
		if (levels[neighbor] == levels[curr] + 1 and weights[curr][neighbor] > 0) {
			path.push_back(neighbor);
			if (dfs(neighbor)) {
				return true;
			}
			path.pop_back();
		}
	}
	return false;
}

long long dinic() {
	// calulate max_flow
	long long max_flow = 0;
	bool has_flow = true;

	while (has_flow) {
		// build level graph
		fill(levels.begin(), levels.end(), 0);
		levels[s] = 1;
		queue<int> q({ s });
		while (!q.empty()) {
			int curr = q.front(); q.pop();
			for (auto neighbor : adj[curr]) {
				if (weights[curr][neighbor] > 0 and levels[neighbor] == 0) {
					levels[neighbor] = levels[curr] + 1;
					q.push(neighbor);
				}
			}
		}

		//if there is flow then use level graph to add flow until blocking flow is reached
		if (levels[t] == 0) {
			has_flow = false;
		}
		else {
			bool flow_found = true;
			while (flow_found) {
				path = { s };
				flow_found = dfs(s);
				if (flow_found) {
					long long bottleneck = 1ll << 62;
					for (int i = 0; i < path.size() - 1; i++) {
						bottleneck = min(bottleneck, weights[path[i]][path[i + 1]]);
					}
					for (int i = 0; i < path.size() - 1; i++) {
						weights[path[i]][path[i + 1]] -= bottleneck;
						weights[path[i + 1]][path[i]] += bottleneck;
					}
					max_flow += bottleneck;
				}
			}
		}
	}

	return max_flow;
}

void min_node_cut_dfs(int curr) {
	visited[curr] = 1;
	for (auto neighbor : adj[curr]) {
		if (!visited[neighbor] and weights[curr][neighbor] > 0) {
			min_node_cut_dfs(neighbor);
		}
	}
}

// find list of nodes in min cut
vector<int> min_node_cut() {
	vector<int> min_cut_list;
	min_node_cut_dfs(s);
	for (int node = 1; node <= maxn; node++) {
		if (visited[node] and !visited[node + maxn]) {
			min_cut_list.push_back( node );
		}
	}
	return min_cut_list;
}

vector<int> minimal_min_node_cut(int n, int max_flow) {
	vector<int> best_set;
	for (int i = 1; i <= n and max_flow; i++) {
		if (i == s or i == t) continue;
		original_weights[i][i + maxn] = 0;
		weights = original_weights;
		if (dinic() == max_flow - 1) {
			best_set.push_back(i);
			max_flow--;
		}
		else {
			original_weights[i][i + maxn] = 1;
		}
	}
	return best_set;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("telecow.in", "r", stdin); freopen("telecow.out", "w", stdout);
	int n, m;
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= n; i++) {
		weights[i][i + maxn] = 1;
		original_weights[i][i + maxn] = 1;
		adj[i].push_back(i + maxn);
		adj[i + maxn].push_back(i);
	}
	weights[s][s + maxn] = weights[t][t + maxn] = 2 * maxn;
	original_weights[s][s + maxn] = original_weights[t][t + maxn] = 2 * maxn;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		if (weights[u + maxn][v] == 0 and weights[v + maxn][u] == 0) {
			adj[u + maxn].push_back(v);
			adj[v].push_back(u + maxn);
			adj[v + maxn].push_back(u);
			adj[u].push_back(v + maxn);
		}
		weights[u+maxn][v] = weights[v + maxn][u] = 2*maxn;
		original_weights[u+maxn][v] = original_weights[v + maxn][u] = 2*maxn;
	}

	int max_flow = dinic();
	cout << max_flow << '\n';

	vector<int> best_set = minimal_min_node_cut(n, max_flow);
	for (int i = 0; i < best_set.size(); i++) {
		cout << best_set[i] << (i != best_set.size() - 1 ? ' ' : '\n');
	}
}