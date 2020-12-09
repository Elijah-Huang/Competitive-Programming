#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	int n, m, k, u, v;
	cin >> n >> m;
	vector<vector<int>> adj(m+1);
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[v].push_back(u);
	}
	cin >> k;
	vector<int> path(k);
	for (int i = 0; i < k; i++) {
		cin >> path[i];
	}
	int dist[200001], alt_dist[200001], next[200001];
	for (int i = 0; i < k - 1; i++) {
		next[path[i]] = path[i + 1];
	}
	int largest = pow(10, 6);
	for (int i = 1; i <= n; i++) {
		dist[i] = largest;
		alt_dist[i] = largest;
	}
	queue<int> q({ path.back() });
	int curr;
	dist[path.back()] = 0;
	while (q.size()) {
		curr = q.front();
		q.pop();
		for (auto neighbor : adj[curr]) {
			if (dist[neighbor] == largest) {
				dist[neighbor] = dist[curr] + 1;
				q.push(neighbor);
			}
			if (alt_dist[neighbor] == largest and next[neighbor] != curr) {
				alt_dist[neighbor] = dist[curr] + 1;
			}
		}
	}
	int mn = 0, mx = 0;
	for (int i = 0; i < k - 1; i++) {
		if (alt_dist[path[i]] == dist[path[i]]) {
			mx++;
		}
		if (dist[path[i + 1]] > dist[path[i]] - 1) {
			mn++;
		}
	}
	cout << mn << ' ' << mx;
}