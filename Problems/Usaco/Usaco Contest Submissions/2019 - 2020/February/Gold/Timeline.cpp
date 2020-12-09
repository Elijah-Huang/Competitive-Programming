#include<bits/stdc++.h>
using namespace std;

struct edge {
	int v, w;
};

vector<vector<edge>> adj(1e5);
vector<int> earliest(1e5);
vector<int> dp(1e5);
vector<bool> visited(1e5);

void dfs(int curr){
	visited[curr] = 1;
	dp[curr] = earliest[curr];
	for (auto neighbor : adj[curr]) {
		if (!visited[neighbor.v]) {
			dfs(neighbor.v);
		}
		dp[curr] = max(dp[curr], dp[neighbor.v] + neighbor.w);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("timeline.in", "r", stdin); freopen("timeline.out", "w", stdout);
	int n, m, c; cin >> n >> m >> c;
	for (int i = 0; i < n; i++) {
		cin >> earliest[i];
	}
	for (int i = 0; i < c; i++) {
		int u, v, w; cin >> u >> v >> w;
		u--; v--;
		adj[v].push_back({ u,w });
	}
	
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	
	for (int i = 0; i < n; i++) {
		cout << dp[i] << '\n';
	}

}