#include<bits/stdc++.h>
#include<queue>
using namespace std;

struct edge {
	int v, w;
};

const int maxn = 1e5 + 1, maxw = 51;
int n, m;
vector<edge> adj[maxn];
int dist[maxn][maxw];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({ v,w });
		adj[v].push_back({ u,w });
	}

	memset(dist, 0x3f, sizeof(dist));
	dist[1][0] = 0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,1*maxw });
	while (!pq.empty()) {
		auto curr = pq.top(); pq.pop();
		int node = curr.second / maxw;
		int w = curr.second % maxw;
		int d = curr.first;

		if (dist[node][w] == d) {
			for (auto n : adj[node]) {
				if (w == 0) {
					if (dist[n.v][n.w] > d) {
						dist[n.v][n.w] = d;
						pq.push({ d,n.v * maxw + n.w });
					}
				}
				else {
					if (dist[n.v][0] > d + (w + n.w) * (w + n.w)) {
						dist[n.v][0] = d + (w + n.w) * (w + n.w);
						pq.push({ d + (w + n.w) * (w + n.w), n.v * maxw });
					}
				}
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (dist[i][0] < 1e9) {
			cout << dist[i][0] << ' ';
		}
		else {
			cout << -1 << ' ';
		}
	}
}