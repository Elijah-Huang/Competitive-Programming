#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;
int team[maxn], visited[maxn];
vector<vector<int>> adj(maxn);

bool dfs(int curr) {
	visited[curr] = 1;

	for (auto neighbor : adj[curr]) {
		if (!visited[neighbor]) {
			team[neighbor] = team[curr] ^ 1;
			if (dfs(neighbor) == false) {
				return false;
			}
		}
		else {
			if (team[neighbor] == team[curr]) {
				return false;
			}
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	bool fail = false;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			if (!dfs(i)) {
				fail = true;
				break;
			}
		}
	}
	if (!fail) {
		for (int i = 1; i <= n; i++) {
			cout << team[i] + 1 << ' ';
		}
	}
	else {
		cout << "IMPOSSIBLE\n";
	}
}