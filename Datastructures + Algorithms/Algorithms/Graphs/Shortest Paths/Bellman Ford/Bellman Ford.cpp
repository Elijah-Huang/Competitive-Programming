#include<bits/stdc++.h>
using namespace std;

// you can find all the nodes in a negative cycle in the nth iteration
// they will be the nodes that are relaxed


struct edge {
	int v, w;
};

int n, m;
vector<vector<edge>> adj;
vector<long long> dist;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	dist.resize(n + 1, 1ll << 62);
	dist[1] = 0;
	adj.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, w; cin >> a >> b >> w;
		adj[a].push_back({ b, w });
	}

	bool neg_cycle = 0;
	bool relaxed = 1;
	int iterations = 0;
	while (relaxed) {
		relaxed = 0;

		for (int i = 1; i <= n; i++) {
			for (auto& edge : adj[i]) {
				if (dist[edge.v] > dist[i] + edge.w) {
					dist[edge.v] = dist[i] + edge.w;
					relaxed = 1;
				}
			}
		}

		iterations++;
		if (iterations == n and relaxed) {
			neg_cycle = 1;
			break;
		}
	}
}