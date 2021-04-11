#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<pair<int,int>>> adj(100001);
int dist[100001];
bool visited[100001];

int dijkstra() {
	memset(dist, 0x3f, sizeof(dist));
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,1 });
	dist[1] = 0;

	while (!pq.empty()) {
		auto curr = pq.top(); pq.pop();

		if (!visited[curr.second]) {
			visited[curr.second] = 1;

			for (auto [u, v] : adj[curr.second]) {
				if (dist[u] > dist[curr.second] + v) {
					dist[u] = dist[curr.second] + v;
					pq.push({ dist[u],u });
				}
			}
		}
	}

	if (dist[n] > 1e9) {
		return -1;
	}
	else {
		return dist[n];
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m;

	while (m--) {
		int a, b, t; cin >> a >> b >> t;
		adj[a].push_back({ b,t });
		adj[b].push_back({ a,t });
	}

	cout << dijkstra();
}