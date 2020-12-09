#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
void floodfill(int curr, vector<vector<int>>& adj, vector<bool>& visited) {
	visited[curr] = 1;
	for (auto neighbor : adj[curr]) {
		if (!visited[neighbor]) {
			floodfill(neighbor, adj, visited);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("closing.in", "r", stdin), freopen("closing.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	vector<bool> removed(n+1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < n; i++) {
		int to_remove;
		if (i) {
			cin >> to_remove;
			removed[to_remove] = 1;
			for (auto neighbor : adj[to_remove]) {
				adj[neighbor].erase(find(adj[neighbor].begin(), adj[neighbor].end(),to_remove));
			}
		}
		int components = 0;
		vector<bool> visited(n+1);
		for (int start = 1; start <= n; start++) {
			if (!removed[start] and !visited[start]) {
				if (components) {
					components++;
					break;
				}
				else {
					components++;
					floodfill(start, adj, visited);
				}
			}
		}
		cout << (components == 1 ? "YES\n" : "NO\n");
	}
}