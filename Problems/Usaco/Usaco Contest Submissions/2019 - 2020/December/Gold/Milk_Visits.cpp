#include<bits/stdc++.h>
using namespace std;

struct query {
	int b, c, idx;
};

int t = 0;
const int maxn = 1e5 + 1;
vector<vector<int>> adj(maxn);
vector<int> types(maxn);
vector<vector<query>> queries(maxn);
vector<int> tin(maxn), tout(maxn);
vector<bool> good_milk(maxn);
vector<vector<int>> last(maxn);
vector<int> path;

void dfs(int curr, int p) {
	tin[curr] = t++;
	for (auto neighbor : adj[curr]) {
		if (neighbor != p) {
			dfs(neighbor, curr);
		}
	}
	tout[curr] = t++;
}

bool in_subtree(int a, int b) {
	return tin[a] <= tin[b] and tout[b] <= tout[a];
}

void dfs2(int curr, int p) {
	path.push_back(curr);
	last[types[curr]].push_back(path.size()-1);

	for (auto& q : queries[curr]) {
		if (!last[q.c].empty()) {
			if (in_subtree(path[last[q.c].back()], q.b)) {
				if (last[q.c].back() == path.size() - 1 or
					!in_subtree(path[last[q.c].back() + 1], q.b)) {
					good_milk[q.idx] = 1;
				}
			}
			else {
				good_milk[q.idx] = 1;
			}
		}
	}
	
	for (auto neighbor : adj[curr]) {
		if (neighbor != p) {
			dfs2(neighbor, curr);
		}
	}

	path.pop_back();
	last[types[curr]].pop_back();
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("milkvisits.in", "r", stdin); freopen("milkvisits.out", "w", stdout);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> types[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		queries[a].push_back({ b, c, i });
		queries[b].push_back({ a, c, i });
	}

	dfs(1, 0);
	dfs2(1, 0);

	for (int i = 0; i < m; i++) {
		cout << good_milk[i];
	}
}