#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(1e5 + 1);
vector<bool> visited(1e5 + 1);
vector<int> components;

void dfs(int curr) {
	visited[curr] = 1;
	for (auto neighbor : adj[curr]) {
		if (!visited[neighbor]) {
			dfs(neighbor);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			components.push_back(i);
			dfs(i);
		}
	}

	cout << components.size() - 1 << '\n';
	for (int i = 0; i < components.size() - 1; i++) {
		cout << components[i] << ' ' << components[i + 1] << '\n';
	}
}