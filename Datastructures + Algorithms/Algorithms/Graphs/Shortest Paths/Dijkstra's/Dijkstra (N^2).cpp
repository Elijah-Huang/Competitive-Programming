#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj;

vector<long long> dijkstra(int start) {
	vector<long long> dist(n + 1, 1ll<<62);
	dist[start] = 0;
	vector<bool> visited(n + 1);

	for (int iters = 0; iters < n; iters++) {
		long long min_dist = 1ll<<62; int min_node = -1;

		for (int j = 1; j <= n; j++) {
			if (!visited[j] and min_dist > dist[j]) {
				min_dist = dist[j];
				min_node = j;
			}
		}

		visited[min_node] = 1;
		for (auto& [neighbor, w] : adj[min_node]) {
			dist[neighbor] = min(dist[neighbor], min_dist + w);
		}
	}

	return dist;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	adj.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b, w; cin >> a >> b >> w;
		adj[a].push_back({ b,w });
		adj[b].push_back({ a,w });
	}
}