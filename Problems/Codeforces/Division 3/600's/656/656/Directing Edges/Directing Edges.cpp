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
	int t;
	cin >> t;
	while (t--) {
		int n, m, idx = 0, curr_comp = 0;
		cin >> n >> m;
		vector<vector<int>> adj(n), adj_undirected(n), radj(n);
		vector<int> comp(n);
		stack<int> topsort;
		vector<int> topsort2(n);
		vector<bool> visited(n);
		for (int i = 0; i < m; i++) {
			int t, u, v;
			cin >> t >> u >> v; u--; v--;
			if (t == 1) {
				adj[u].push_back(v);
				radj[v].push_back(u);
			}
			else {
				adj_undirected[u].push_back(v);
			}
		}
		for (int i = 0; i < n; i++) {
			if (visited[i] == 0) {
				topdfs(i, visited, adj, topsort);
			}
		}
		while (!topsort.empty()) {
			int curr = topsort.top();
			topsort.pop();
			topsort2[curr] = idx++;
			if (comp[curr] == 0) {
				curr_comp++;
				flooddfs(curr, comp, radj, curr_comp);
			}
		}
		if (curr_comp < n) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
			for (int u = 0; u < n; u++) {
				for (auto v : adj[u]) {
					cout << u + 1 << ' ' << v + 1 << '\n';
				}
			}
			for (int u = 0; u < n; u++) {
				for (auto v : adj_undirected[u]) {
					if (topsort2[u] < topsort2[v]) {
						cout << u + 1 << ' ' << v + 1 << '\n';
					}
					else {
						cout << v + 1 << ' ' << u + 1 << '\n';
					}
				}
			}
		}
	}
}