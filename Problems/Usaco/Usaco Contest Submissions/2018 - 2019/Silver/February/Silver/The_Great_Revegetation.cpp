#include <bits/stdc++.h>
using namespace std;
void dfs(int curr, bool& fail, vector<vector<pair<int, char>>>& adj, vector<int>& pastures) {
	if (!fail) {
		for (auto neighbor : adj[curr]) {
			if (pastures[neighbor.first] == 0) {
				if (neighbor.second == 'S') {
					pastures[neighbor.first] = pastures[curr];
				}
				else {
					pastures[neighbor.first] = (pastures[curr] == 1 ? 2 : 1);
				}
				dfs(neighbor.first, fail, adj, pastures);
				if (fail) {
					break;
				}
			}
			else if (pastures[neighbor.first] == pastures[curr] and neighbor.second == 'D') {
				fail = true;
				break;
			}
			else if (pastures[neighbor.first] != pastures[curr] and neighbor.second == 'S') {
				fail = true;
				break;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("revegetate.in","r",stdin); freopen("revegetate.out","w",stdout);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, char>>> adj(n+1);
	for (int i = 0; i < m; i++) {
		char type;
		int u, v;
		cin >> type >> u >> v;
		adj[u].push_back({ v,type });
		adj[v].push_back({ u,type });
	}
	vector<int> pastures(n + 1);
	int components = 0;
	bool fail = false;
	for (int start = 1; start <= n; start++) {
		if (fail) {
			break;
		}
		if (pastures[start] == 0) {
			components++;
			pastures[start] = 1;
			dfs(start, fail, adj, pastures);
		}
	}
	cout << (fail ? "0" : "1" + string(components, '0'));
}