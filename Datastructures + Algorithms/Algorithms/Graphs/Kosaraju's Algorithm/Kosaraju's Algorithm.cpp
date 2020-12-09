#include<bits/stdc++.h>
using namespace std;

void topdfs(int curr, vector<bool>& visited, vector<vector<int>>& adj, stack<int>& topsort) {
	visited[curr] = 1;
	for (auto neighbor : adj[curr]) {
		if (!visited[neighbor]) {
			topdfs(neighbor, visited, adj, topsort);
		}
	}
	topsort.push(curr);
}

void flooddfs(int curr, vector<int>& comp, vector<vector<int>>& radj, int& curr_comp) {
	comp[curr] = curr_comp;
	for (auto neighbor : radj[curr]) {
		if (comp[neighbor] == 0) {
			flooddfs(neighbor, comp, radj, curr_comp);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, curr_comp = 0;
	cin >> n >> m;
	vector<vector<int>> adj(n), radj(n);
	vector<int> comp(n);
	stack<int> topsort;
	vector<bool> visited(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v; u--; v--;
		adj[u].push_back(v);
		radj[v].push_back(u);
	}
	for (int i = 0; i < n; i++) {
		if (visited[i] == 0) {
			topdfs(i, visited, adj, topsort);
		}
	}
	while (!topsort.empty()) {
		int curr = topsort.top();
		topsort.pop();
		if (comp[curr] == 0) {
			curr_comp++;
			flooddfs(curr, comp, radj, curr_comp);
		}
	}
}