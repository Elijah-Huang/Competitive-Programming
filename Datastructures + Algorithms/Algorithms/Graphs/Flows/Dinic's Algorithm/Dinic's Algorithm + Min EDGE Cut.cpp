//Can probably do Min Cut with repeated edges by adding a new node (idx > n) inbetween the repeated edge
//If edge in min cut and one of the endpoints has idx > n then u know the other neighbor is the true endpoint
/*Also there are multiple cuts with repeated edges(so they may have to put restrictions) so you can combine 
them into one big edge for max flow calcuation, and then take whichever repeated edges suit the restrictions*/


/*Actually simplest way is that if the repeated edges weights combined are all used, they are all part of
the min cut otherwise the min cut can always be found somewhere else*/

// Use of adjacency matrix makes coding easier, but it takes extra memory and insignificant extra time

//For least edges in min cut, add weight = weight*(n+1) + 1, that way for equal min cut's, smaller #edges win

#include<bits/stdc++.h>
using namespace std;

int s, t;
const int maxn = 1000;
vector<vector<int>> adj(maxn + 1);
vector<vector<long long>> weights(maxn + 1, vector<long long>(maxn + 1));
// original is used for the edge case of originaly 0 weight edges when checking min cut
vector<vector<int>> original(maxn + 1, vector<int>(maxn + 1));
vector<int> visited(maxn + 1);
vector<int> levels(maxn + 1);
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
				path.clear();
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

void min_cut_dfs(int curr) {
	visited[curr] = 1;
	for (auto neighbor : adj[curr]) {
		if (!visited[neighbor] and weights[curr][neighbor] > 0) {
			min_cut_dfs(neighbor);
		}
	}
}

// find list of edges in min cut
vector<pair<int, int>> min_cut() {
	vector<pair<int, int>> min_cut_list;
	min_cut_dfs(1);
	for (int node = 1; node <= maxn; node++) {
		if (visited[node]) {
			for (auto neighbor : adj[node]) {
				if (!visited[neighbor] and original[node][neighbor]) {
					min_cut_list.push_back({ node,neighbor });
				}
			}
		}
	}

	return min_cut_list;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	s = 1, t = n;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		if (weights[u][v] == 0 and weights[v][u] == 0) {
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		weights[u][v] += w;
		original[u][v] = 1;
	}

	int max_flow = dinic();
	cout << max_flow << '\n';
}