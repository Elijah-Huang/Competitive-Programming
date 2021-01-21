#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("rblock.in", "r", stdin); freopen("rblock.out", "w", stdout);
	int n, m; cin >> n >> m;
	vector<vector<pair<int, int>>> adj(n);
	for (int i = 0; i < m; i++) {
		int a, b, w; cin >> a >> b >> w;
		a--; b--;
		adj[a].push_back({ b,w });
		adj[b].push_back({ a,w });
	}

	priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
	pq.push({ 0,{-1,0} });
	vector<int> dists(n, 1 << 30);
	vector<int> parent(n);
	while (!pq.empty()) {
		auto curr = pq.top(); pq.pop();
		if (curr.first < dists[curr.second.second]) {
			dists[curr.second.second] = curr.first;
			parent[curr.second.second] = curr.second.first;
			for (auto neighbor : adj[curr.second.second]) {
				pq.push({ curr.first + neighbor.second, {curr.second.second,neighbor.first } });
			}
		}
	}

	int original_min = dists[n - 1];
	int mx_change = 0;
	int curr = n - 1;
	while (curr != 0) {
		int v = curr; int u = parent[curr];
		for (int i = 0; i < adj[u].size(); i++) {
			if (adj[u][i].first == v) {
				adj[u][i].second *= 2;
			}
		}
		for (int i = 0; i < adj[v].size(); i++) {
			if (adj[v][i].first == u) {
				adj[v][i].second *= 2;
			}
		}

		priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
		pq.push({ 0,0 });
		vector<int> dists(n, 1 << 30);
		while (!pq.empty()) {
			auto curr = pq.top(); pq.pop();
			if (curr.first < dists[curr.second]) {
				dists[curr.second] = curr.first;
				for (auto neighbor : adj[curr.second]) {
					pq.push({ curr.first + neighbor.second, neighbor.first  });
				}
			}
		}

		mx_change = max(mx_change, dists[n - 1] - original_min);

		for (int i = 0; i < adj[u].size(); i++) {
			if (adj[u][i].first == v) {
				adj[u][i].second /= 2;
			}
		}
		for (int i = 0; i < adj[v].size(); i++) {
			if (adj[v][i].first == u) {
				adj[v][i].second /= 2;
			}
		}

		curr = parent[curr];
	}

	cout << mx_change;
}