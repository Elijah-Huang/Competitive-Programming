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
	vector<int> relaxed(n + 1);
	vector<bool> in_queue(n + 1);
	queue<int> q; q.push(1);
	while (!q.empty() and !neg_cycle) {
		int curr = q.front(); q.pop();
		in_queue[curr] = 0;

		for (auto neighbor : adj[curr]) {
			if (dist[neighbor.v] > dist[curr] + neighbor.w) {
				dist[neighbor.v] = dist[curr] + neighbor.w;
				if (!in_queue[neighbor.v]) {
					q.push(neighbor.v);
					in_queue[neighbor.v] = 1;
					relaxed[neighbor.v]++;
					if (relaxed[neighbor.v] == n) {
						neg_cycle = 1;
						break;
					}
				}
			}
		}
	}
}