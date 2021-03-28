// O(E*log(E)) good for sparse graphs
// optimized via not pushing new nodes if dist is greater and breaking if all nodes have been visited
#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj;

vector<long long> dijkstra_pq(int start) {
	vector<long long> dist(n + 1, 1ll << 62);
	dist[start] = 0;
	priority_queue<tuple<long long, int>, vector<tuple<long long, int>>, greater<tuple<long long, int>>> pq;
	vector<bool> visited(n + 1);
	long long d, new_d; int node, tot_vis = 0;

	pq.push({ 0,start });
	while (!pq.empty()) {
		tie(d, node) = pq.top(); pq.pop();

		if (!visited[node]) {
			visited[node] = 1;
			if (++tot_vis == n) {
				break;
			}

			for (auto& [neighbor, w] : adj[node]) {
				new_d = d + w;
				if (new_d < dist[neighbor]) {
					dist[neighbor] = new_d;
					pq.push({ new_d, neighbor });
				}
			}
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