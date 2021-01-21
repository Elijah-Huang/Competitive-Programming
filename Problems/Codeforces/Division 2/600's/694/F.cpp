#include<bits/stdc++.h>
using namespace std;

int t, n, m;
vector<vector<int>> adj;
vector<int> color;
vector<int> teachers;
bool fail;

void dfs(int c) {
	if (color[c] == 1) {
		for (auto n : adj[c]) {
			if (color[n] == 0) {
				dfs(n);
			}
		}
	}
	else {
		color[c] = 2;
		vector<int> to_dfs;
		for (auto n : adj[c]) {
			if (color[n] == 0) {
				color[n] = 1;
				to_dfs.push_back(n);
			}
		}
		for (auto n : to_dfs) {
			dfs(n);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> t;

	while (t--) {
		cin >> n >> m;

		adj.resize(n + 1);
		color.resize(n + 1);
		for (int i = 0; i < m; i++) {
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		dfs(1);

		fail = false;
		for (int i = 1; i <= n; i++) {
			if (color[i] == 0) {
				fail = true;
				break;
			}
			else if (color[i] == 2) {
				teachers.push_back(i);
			}
		}

		if (!fail and teachers.size()) {
			cout << "YES\n";
			cout << teachers.size() << '\n';
			for (auto i : teachers) {
				cout << i << ' ';
			}
			cout << '\n';
		}
		else {
			cout << "NO\n";
		}

		adj.clear();
		color.clear();
		teachers.clear();
	}
}