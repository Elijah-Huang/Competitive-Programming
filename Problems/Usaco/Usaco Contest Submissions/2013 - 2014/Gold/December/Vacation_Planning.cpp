#include<bits/stdc++.h>
using namespace std;

struct edge {
	int v, w;
};

struct loc_cmp {
	bool operator()(const edge& a, const edge& b) const {
		return a.w > b.w;
	}
};

int n, m, k, q;
const int maxn = 2e4 + 1, max_dist = 2e8;
int possible = 0;
long long tot_dist = 0;
int dist[200][maxn][2];
vector<edge> adj[maxn][2];

void dijkstra(int hub, int idx) {
	for (int i = 0; i < 2; i++) {
		priority_queue<edge, vector<edge>, loc_cmp> pq;
		pq.push({ hub, 0 });
		while (!pq.empty()) {
			auto curr = pq.top(); pq.pop();
			if (curr.w < dist[idx][curr.v][i]) {
				dist[idx][curr.v][i] = curr.w;
				for (auto neighbor : adj[curr.v][i]) {
					pq.push({ neighbor.v,curr.w + neighbor.w });
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	freopen("vacationgold.in", "r", stdin); freopen("vacationgold.out", "w", stdout);

	cin >> n >> m >> k >> q;

	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u][0].push_back({ v,w });
		adj[v][1].push_back({ u,w });
	}

	memset(dist, 0x3f, sizeof(dist));
	for (int i = 0; i < k; i++) {
		int hub; cin >> hub;
		dijkstra(hub, i);
	}

	while (q--) {
		int a, b; cin >> a >> b;
		int mn_dist = max_dist;
		for (int i = 0; i < k; i++) {
			mn_dist = min(mn_dist, dist[i][a][1] + dist[i][b][0]);
		}

		if (mn_dist != max_dist) {
			possible++;
			tot_dist += mn_dist;
		}
	}

	cout << possible << '\n';
	cout << tot_dist;
}