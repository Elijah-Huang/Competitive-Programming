#include<bits/stdc++.h>
using namespace std;

struct edge {
	int v, L, c;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("mroute.in", "r", stdin); freopen("mroute.out", "w", stdout);
	int n, m;
	double x;
	cin >> n >> m >> x;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	vector<vector<edge>> adj(n);
	vector<double> bottle_neck_vals(m);
	double least_dist = 1ll << 35;
	for (int i = 0; i < m; i++) {
		int u, v, L, c;
		cin >> u >> v >> L >> c;
		u--; 
		v--;
		adj[u].push_back({ v,L,c });
		adj[v].push_back({ u,L,c });
		bottle_neck_vals[i] = c;
	}
	for (auto bottleneck : bottle_neck_vals) {
		vector<double> dist(n, 1ll << 35);
		priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> pq;
		pq.push({ 0,0 });
		while (!pq.empty()) {
			auto curr = pq.top();
			pq.pop();
			if (dist[curr.second] > curr.first) {
				dist[curr.second] = curr.first;
				for (auto neighbor : adj[curr.second]) {
					if (neighbor.c >= bottleneck and 
						dist[neighbor.v] > curr.first + neighbor.L ){
						pq.push({ curr.first + neighbor.L, neighbor.v });
					}
				}
			}
		}
		least_dist = min(least_dist, dist[n - 1] + x / bottleneck);
	}
	if (fabs(ceil(least_dist) -least_dist) < 1e-5) {
		cout << int(ceil(least_dist));
	}
	else {
		cout << int(least_dist);
	}
	
}