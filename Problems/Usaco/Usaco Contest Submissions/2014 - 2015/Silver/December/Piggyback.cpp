#include<bits/stdc++.h>
using namespace std;

const long long most_dist = 1ll << 40;

void bfs(int start, vector<long long>& dist, vector<vector<int>>& adj) {
	queue<pair<int, int>> q({ { start,0 } });
	while (!q.empty()) {
		pair<int, int> curr = q.front(); q.pop();
		if (dist[curr.first] == most_dist) {
			dist[curr.first] = curr.second;
			for (auto neighbor : adj[curr.first]) {
				q.push({ neighbor, curr.second + 1 });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("piggyback.in", "r", stdin); freopen("piggyback.out", "w", stdout);
	int b, e, p, n, m; cin >> b >> e >> p >> n >> m;
	vector<vector<int>> adj(n);
	vector<int> weight = { b,e,p };
	vector<vector<long long>> dists(3, vector<long long>(n, most_dist));
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bfs(0, dists[0], adj);
	bfs(1, dists[1], adj);
	bfs(n - 1, dists[2], adj);
	
	long long min_dist = 1ll << 60;
	for (int meet = 0; meet < n; meet++) {
		long long total_dist = 0;
		for (int i = 0; i < 3; i++) {
			total_dist += weight[i] * dists[i][meet];
		}
		min_dist = min(min_dist, total_dist);
	}

	cout << min_dist << '\n';
}