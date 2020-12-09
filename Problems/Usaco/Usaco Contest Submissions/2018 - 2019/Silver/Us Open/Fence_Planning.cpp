#include<bits/stdc++.h>
using namespace std;

struct cow {
	int x, y;
};

void dfs(int curr, int& curr_comp, vector<vector<int>>& adj,
	vector<vector<int>>& components, vector<bool>& visited) {
	visited[curr] = 1;
	components[curr_comp].push_back(curr);
	for (auto neighbor : adj[curr]) {
		if (!visited[neighbor]) {
			dfs(neighbor, curr_comp, adj, components, visited);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	freopen("fenceplan.in", "r", stdin); freopen("fenceplan.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<cow> cows(n);
	vector<vector<int>> adj(n);
	vector<vector<int>> components;
	vector<bool> visited(n);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		cows[i] = { x,y };
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int curr_comp = -1;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			curr_comp++;
			components.resize(curr_comp + 1);
			dfs(i, curr_comp, adj, components, visited);
		}
	}
	int min_perimeter = 1 << 30;
	for (auto comp : components) {
		int min_x = 1 << 30, min_y = 1 << 30, max_y = 0, max_x = 0;
		for (auto idx : comp) {
			min_x = min(cows[idx].x, min_x);
			min_y = min(cows[idx].y, min_y);
			max_x = max(cows[idx].x, max_x);
			max_y = max(cows[idx].y, max_y);
		}
		min_perimeter = min(min_perimeter, 2 * (max_x - min_x + max_y - min_y));
	}
	cout << min_perimeter;

}