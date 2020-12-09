#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;
int visited[maxn], onpath[maxn];
vector<int> path;
vector<vector<int>> adj(maxn);

bool dfs(int curr) {
	visited[curr] = 1;
	path.push_back(curr);
	onpath[curr] = 1;

	for (auto neighbor : adj[curr]) {
		if (!visited[neighbor]) {
			if (dfs(neighbor)) {
				return true;
			}
		}
		else if (onpath[neighbor]) {
			if (path.size() >= 3) {
				if (neighbor != path[path.size()-1] and neighbor != path[path.size() - 2]) {
					path.push_back(neighbor);
					vector<int> cycle;
					for (int i = path.size() - 1; i >= 0; i--) {
						cycle.push_back(path[i]);
						if (path[i] == neighbor and i != path.size() - 1) {
							cout << cycle.size() << '\n';
							for (auto i : cycle) {
								cout << i << ' ';
							}
							return true;
						}
					}
				}
			}
		}
	}

	onpath[curr] = 0;
	path.pop_back();
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	bool cycle_found = false;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			if (dfs(i)) {
				cycle_found = true;
				break;
			}
		}
	}
	if (!cycle_found) {
		cout << "IMPOSSIBLE\n";
	}
}